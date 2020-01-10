#include "fillit_start.h"

int     print_error(int p)
{
	if (p == 2)
		ft_putstr("error\n");
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}

int		solve(int fd)
{
	tetramino *fig;

	if ((fig = get_tetramino(fd, 'A')))
		return (1);
	return (0);
}

int		main(int ac, char **av)
{
	int		fd;
	int		read_var;
	char	*str;

	str = av[1];
//	ft_putstr(str);
	if (ac == 2)
	{
		fd = open(str, O_RDONLY);
		read_var = read(fd, str, 0);
		if (read_var == 0)
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
