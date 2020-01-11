#include "../includes/fillit.h"

static int		print_error(int p)
{
	if (p == 2)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit [map_file_name]\n");
	return (0);
}

int		solve(int fd)
{
	tetramino *fig;
	tetramino *tmp;

	if ((fig = get_tetramino(fd, 'A')))
	{
		tmp = fig;
		ft_putnbr(get_map_size(tmp));
		write(1, "\n\n\n", 3);
		while (tmp)
		{
			print_fig(tmp->map, tmp->map_size, tmp->letter);
			print_fig_param(tmp);
			tmp = tmp->next;
		}
		tmp = fig;
		resize(tmp, 6);
		while (tmp)
		{
			print_fig(tmp->map, tmp->map_size, tmp->letter);
			print_fig_param(tmp);
			tmp = tmp->next;
		}
		tmp = fig;
		resize(tmp, 3);
		while (tmp)
		{
			print_fig(tmp->map, tmp->map_size, tmp->letter);
			print_fig_param(tmp);
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
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
