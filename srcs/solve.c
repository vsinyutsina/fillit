/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 16:32:05 by akelli            #+#    #+#             */
/*   Updated: 2020/01/17 16:32:24 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		next_position(t_tetramino *figure, t_border map_border,
		t_other_figures other_figures)
{
	if (figure->map == figure->map_begin
	&& other_figures.last[figure->type])
		figure->map = other_figures.last[figure->type];
	while (figure->map & other_figures.all)
		if (!shift(figure, map_border))
			return (0);
	return (1);
}

int		shift(t_tetramino *figure, t_border map_border)
{
	if (!(figure->map & map_border.right))
		figure->map >>= 1;
	else
		figure->map >>= figure->width;
	return (figure->map & map_border.bottom ? 0 : 1);
}

void	reset(t_tetramino *figure)
{
	if (!figure)
		return ;
	figure->map = figure->map_begin;
	figure->map_extended = 0;
	reset(figure->next);
}

int		fill_figures(t_tetramino *figure, t_border map_border,
		t_other_figures other_figures)
{
	int	next_figure;

	if (!figure)
		return (0);
	if (next_position(figure, map_border, other_figures))
	{
		other_figures.last[figure->type] = figure->map;
		while ((next_figure = fill_figures(figure->next, map_border,
				new_other_figures(other_figures, figure))))
		{
			if (next_figure == figure->type)
				return (next_figure);
			if (!shift(figure, map_border))
				return (-1);
			other_figures.last[figure->type] = figure->map;
			if (!next_position(figure, map_border, other_figures))
				return (-1);
			other_figures.last[figure->type] = figure->map;
			reset(figure->next);
		}
		return (0);
	}
	return (figure->type);
}
