#include "../includes/fillit.h"

static int		print_error(int p)
{
	if (p == 2)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit [map_file_name]\n");
	return (0);
}

int				solve(int fd)
{
	t_tetramino	*fig;
	int			map_size;
	t_border		map_border;

	if ((fig = init_tetramino(fd, 'A')))
	{
		map_size = get_map_size(fig);
		resize(fig, map_size);
		map_border = get_map_border(map_size);
		get_type(fig);
		print_all(fig, 1);
		map_border.other_figures |= fig->map >> 5;
		map_border.last_figure[8] = fig->next->map >> 6;
		next_position(fig->next, map_border);
		print(fig->next, 1);
		return (1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((read(fd, av[1], 0) == 0))
		{
			if (solve(fd))
			{
				close(fd);
				return (0);
			}
		}
		close(fd);
	}
	print_error(ac);
	return (-1);
}
