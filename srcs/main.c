#include "../includes/fillit.h"

static int		print_error(int p)
{
	if (p == 2)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit [map_file_name]\n");
	return (0);
}
/*
void			solve(t_tetramino *fig)
{
	int				map_size;
	t_border		map_border;
	t_other_figures other_figures;

	get_type(fig);
	map_size = get_map_size(fig);
	resize(fig, map_size);
	map_border = get_map_border(map_size);
	other_figures = get_other_figures();
	while (fill_figures(fig, map_border, other_figures))
	{
		map_size++;
		map_border = get_map_border(map_size);
		resize(fig, map_size);
	}
	print_map(fig);
	free_figures(fig);
}
*/
static void			solve(t_tetramino *figure, t_border *map_border,
				t_other_figures *other_fig)
{
	int		(*fill) (t_tetramino *fig, t_border map_bor, t_other_figures other);
	t_border	(*border) (int map_size);

	if (!map_border)
	{
		figure->map_size = get_map_size(figure);
		get_type(figure);
		border = figure->map_size < 12 ?  get_map_border : get_map_border_ext;
		*map_border = border(figure->map_size);
		resize(figure, figure->map_size);
		*other_fig = get_other_figures();
	}
	fill = figure->map_size < 12 ? fill_figures : fill_figures_ext;
	if (fill(figure, *map_border, *other_fig))
	{
		resize(figure, figure->map_size + 1);
		border = figure->map_size < 12 ?  get_map_border : get_map_border_ext;
		*map_border = border(figure->map_size);
		solve(figure, map_border, other_fig);
	}
	else
	{
		print_map(figure);
		free_figures(figure);
	}
}

int				main(int ac, char **av)
{
	int			fd;
	t_tetramino	*fig;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((read(fd, av[1], 0) == 0))
		{
			if ((fig = init_tetramino(fd, 'A')))
			{
				solve(fig, NULL, NULL);
				close(fd);
				return (0);
			}
		}
		close(fd);
	}
	print_error(ac);
	return (-1);
}
