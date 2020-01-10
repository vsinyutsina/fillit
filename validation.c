#include "fillit_start.h"

static __uint128_t     move_to_top(__uint128_t map)
{
	__uint128_t         left_board;

	left_board = 0x8888;
	map <<= 112;
	while (!(map >> 124))
		map <<= 4;
	while (((left_board << 112) & map) == 0)
		map <<= 1;
	print_uint(map, 127, 'T');
	printf("\n");
	return (map);
}

static __uint128_t		validation(__uint128_t	map)
{
	int			connect;
	int			n_hash;
	int			i;

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
	print_uint(map, 127, 'V');
	printf("\n");
	map = move_to_top(map);
	return (map);
}

static __uint128_t		str_to_nbr(int fd)
{
	__uint128_t	map;
	char		byte;
	int			i;

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
	print_uint(map, 127, 'S');
	printf("\n");
	return (validation(map));
}

tetramino		*get_tetramino(int fd, char letter)
{
	tetramino	*figure;
	char		tab;

	if (!(figure = (tetramino*)malloc(sizeof(tetramino)))
		|| letter > 'Z')
		return (NULL);

//	printf("New figure");

	if (!(figure->map = str_to_nbr(fd)))
	{
		free(figure);
		figure = NULL;
		return (NULL);
	}
	figure->size = 4;
	figure->letter = letter;
	figure->next = NULL;
	if (read(fd, &tab, 1))
		if (tab != '\n' || !(figure->next = get_tetramino(fd, letter + 1)))
		{
			free(figure);
			figure = NULL;
		}
	print_uint(figure->map, 127, 'R');
	printf("\n");
	return (figure);
}