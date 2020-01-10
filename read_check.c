#include "fillit_start.h"

int     print_error(int p)
{
	if (p == 2)
		ft_putstr("Идиот, используй К О Н СОЛЬ!!!!!!!\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

void    print_uint(__uint128_t line, int size, char l)
{
	if (size)
		print_uint(line >> 1, size - 1, l);
	if (!(size % 16))
		printf("\n");
	if (line % 2)
		printf("%c ", l);
	else
		printf(". ");
}

int		solve(int fd)
{
	tetramino *fig;

	if ((fig = get_tetramino(fd, 'A')))
	{
		while (fig)
		{
//			ft_putstr("new map\n");
			print_uint(fig->map, 127, '#');
			fig = fig->next;
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
		fd = open("read_check", O_RDONLY);
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
