#include "fillit_start.h"

int     print_error(int p)
{

    if (p == 2)
        ft_putstr("error\n");
    if (p == 1)
        ft_putstr("usage: ./fillit source_file\n");
    return (0) ;
}

int     solve(int fd, char *figure)
{
    tetramino *fig;

    if ((fig = get_tetramino(fd, 'A')))
        return (1);
    return (0);
}

int     main(int ac, char **av)
{
    int fd;

    if (ac == 2)
    {
        fd = open(av[1], O_RDONLY);
        if (read(fd, av[1], 0) == 0)
        {
            if (solve(fd, av[1]))
            {
                close(fd);
                return (0);
            }
        }
        close(fd);
        print_error(2);
        return (-1);
    }
    print_error(1);
    return (-1);
}
