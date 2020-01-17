#include "../includes/fillit.h"

static void		increase_size(t_tetramino *fig, int new_size)
{
	int			i;
	int			delta;
	__uint128_t	mask;

	delta = ABS(fig->map_size - new_size);
	mask = -1;
	mask >>= fig->map_size;
	i = 0;
	while (i++ < 3)
	{
		fig->map = (fig->map & ~mask) | ((fig->map & mask) >> (delta));
		mask >>= new_size;
	}
}

static void		reduce_size(t_tetramino *fig, int new_size)
{
	int			i;
	int			delta;
	__uint128_t	mask;

	fig->map = fig->map_begin;
	delta = fig->map_size - new_size;
	mask = -1;
	i = 0;
	while (i++ < 3)
	{
		mask >>= new_size;
		fig->map = (fig->map & ~mask) | ((fig->map << delta) & mask);
	}
}

void			resize(t_tetramino *fig, int new_size)
{
	if (fig == NULL)
		return ;
	fig->map = fig->map_begin;
	if (new_size > fig->map_size)
		increase_size(fig, new_size);
	else if (new_size < fig->map_size)
		reduce_size(fig, new_size);
	fig->map_begin = fig->map;
	fig->map_size = new_size;
	resize(fig->next, new_size);
}

int				get_map_size(t_tetramino *figure)
{
	t_tetramino	*tmp;
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

t_border		get_map_border(int map_size)
{
	t_border	map_border;
	int			i;

	map_border.right = 1;
	i = 0;
	while (i++ < map_size)
		map_border.right = (map_border.right << map_size) + 1;
	map_border.right <<= 128 - map_size * map_size;
	map_border.bottom = -1;
	map_border.bottom >>= map_size * map_size;
	return (map_border);
}
