//
// Created by Fredia Wiley on 11/01/2020.
//

#include "../includes/fillit.h"

void	resize(tetramino *fig, int new_size)
{
	int			i;
	int			delta;
	__uint128_t	mask;

	if (!fig)
		return ;
	fig->map = fig->map_begin;
	delta = ABS(fig->map_size - new_size);
	mask = -1;
	i = 0;
	mask >>= fig->map_size * (new_size < fig->map_size ? 3 : 1);
	while (i++ < 3)
	{
		if (new_size < fig->map_size)
			fig->map = ((fig->map & mask) << delta)
					| (fig->map & ~((mask <<= delta)));
		else
			fig->map = (fig->map & ~mask)
					| ((fig->map & mask) >> (delta));
		mask = new_size < fig->map_size ? mask << new_size : mask >> new_size;
	}
	fig->map_begin = fig->map;
	fig->map_size = new_size;
	resize(fig->next, new_size);
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
