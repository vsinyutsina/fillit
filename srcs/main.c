#include "../includes/fillit.h"

static int		print_error(int p)
{
	if (p == 2)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit [map_file_name]\n");
	return (0);
}

static void		solve(t_tetramino *figure, t_border *map_border,
				t_other_figures *other_fig)
{
	int			map_size;
	t_border	(*border) (int map_size);
	int			(*fill) (t_tetramino *fig, t_border bor, t_other_figures other);

	map_size = figure->map_size;
	fill = map_size < 12 ? fill_figures : fill_figures_ext;
	if (fill(figure, *map_border, *other_fig))
	{
		resize(figure, map_size + 1);
		border = figure->map_size < 12 ? get_map_border : get_map_border_ext;
		*map_border = border(figure->map_size);
		solve(figure, map_border, other_fig);
	}
	else
	{
		print_map(figure);
		free_figures(figure);
	}
}

static	void	init_solve(t_tetramino *figure, t_border *map_border,
				t_other_figures *other_figures)
{
	t_border	(*border) (int map_size);
	int			map_size;

	map_size = get_map_size(figure);
	get_type(figure);
	border = map_size < 12 ? get_map_border : get_map_border_ext;
	*map_border = border(map_size);
	resize(figure, map_size);
	*other_figures = get_other_figures();
}

int				main(int ac, char **av)
{
	int					fd;
	t_tetramino			*figure;
	t_border			map_border;
	t_other_figures		other_fig;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((read(fd, av[1], 0) == 0))
		{
			if ((figure = init_tetramino(fd, 'A')))
			{
				init_solve(figure, &map_border, &other_fig);
				solve(figure, &map_border, &other_fig);
				close(fd);
				return (0);
			}
		}
		close(fd);
	}
	print_error(ac);
	return (-1);
}
