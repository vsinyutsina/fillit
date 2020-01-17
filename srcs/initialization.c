/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:58:31 by akelli            #+#    #+#             */
/*   Updated: 2020/01/17 16:58:33 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void				get_default_value(t_tetramino *figure, char letter)
{
	__uint128_t			right_board;

	if (!figure)
		return ;
	figure->map_extended = 0;
	figure->map_begin = figure->map;
	figure->map_size = 4;
	figure->letter = letter;
	figure->type = 0;
	figure->next = NULL;
	figure->height = 0;
	while ((figure->map << (figure->height * 4)) && figure->map)
		figure->height++;
	right_board = 0x1111;
	right_board <<= 112;
	figure->width = 4;
	while (!(figure->map & right_board) && figure->width)
	{
		figure->width--;
		right_board <<= 1;
	}
}

static __uint128_t		move_to_top(__uint128_t map)
{
	__uint128_t			left_board;

	left_board = 0x8888;
	map <<= 112;
	while (!(map >> 124))
		map <<= 4;
	while (((left_board << 112) & map) == 0)
		map <<= 1;
	return (map);
}

static __uint128_t		validation(__uint128_t map)
{
	int					connect;
	int					n_hash;
	int					i;

	connect = 0;
	n_hash = 0;
	i = 0;
	while (i < 16)
	{
		if ((map << (112 + i)) >> 127)
		{
			n_hash++;
			if (i / 4 == (i - 1) / 4)
				connect += map << (i + 111) >> 127;
			if (i / 4 == (i + 1) / 4)
				connect += map << (i + 113) >> 127;
			connect += map << (i + 108) >> 127;
			connect += map << (i + 116) >> 127;
		}
		i++;
	}
	if (n_hash != 4 || (connect != 6 && connect != 8))
		return (0);
	map = move_to_top(map);
	return (map);
}

static __uint128_t		str_to_nbr(int fd)
{
	__uint128_t			map;
	char				byte;
	int					i;

	map = 0;
	i = 0;
	while (i++ < 20)
	{
		if (!(read(fd, &byte, 1)))
			return (0);
		if (i % 5)
		{
			if (byte != '.' && byte != '#')
				return (0);
			map <<= 1;
			if (byte == '#')
				map++;
		}
		else if (byte != '\n')
			return (0);
	}
	return (validation(map));
}

t_tetramino				*init_tetramino(int fd, char letter)
{
	t_tetramino			*figure;
	char				tab;

	if (!(figure = (t_tetramino*)malloc(sizeof(t_tetramino)))
		|| letter > 'Z')
		return (NULL);
	if (!(figure->map = str_to_nbr(fd)))
	{
		free(figure);
		figure = NULL;
		return (NULL);
	}
	get_default_value(figure, letter);
	if (read(fd, &tab, 1))
		if (tab != '\n' || !(figure->next = init_tetramino(fd, letter + 1)))
		{
			free(figure);
			figure = NULL;
		}
	return (figure);
}
