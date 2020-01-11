//
// Created by Fredia Wiley on 11/01/2020.
//

#include "../includes/fillit.h"

void	resize(tetramino *figure, int new_size)
{
	int			i;
	__uint128_t	mask;

	if (!figure)
		return ;
	resize(figure->next, new_size);
	figure->map = figure->map_begin;
	i = 0;
	if (new_size > figure->map_size)
	{
		mask = -1;
		mask >>= figure->map_size;
		while (i < 3)
		{
//			figure->map = ()
//			print_fig(figure->map, 4, '$');
			mask >>= new_size;
			i++;
		}
		figure->map_begin = figure->map;
		figure->map_size = new_size;
	}
}

int		get_map_size(tetramino *figure)
{
	tetramino	*tmp;
	int			counter_figures;
	int			map_size;
	int			area;

	if (!figure)
		return (0);
	tmp = figure;
	counter_figures = 0;
	map_size = 2;
	while (tmp)
	{
		map_size = tmp->width > map_size ? tmp->width : map_size;
		map_size = tmp->height > map_size ? tmp->height : map_size;
		counter_figures++;
		tmp = tmp->next;
	}
	area = counter_figures * 4;
	while (map_size * map_size < area)
		map_size++;
	return (map_size);
}
