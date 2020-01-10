#include <stdio.h>
#include "fillit_start.h"

tetramino   *fig_to_tet(char *pos_f, int map_size)
{
    int         i; 
    int         w; 
    tetramino   *tet; 

    i = 1;
    w = 0;
    tet->map = 0; 
    while (pos_f) 
    {
        w = (*pos_f == '#') ? w + 1 : w;
        tet->map = (*pos_f == '#') ? tet->map + 1 : tet->map; 
        tet->map <<= 1; 
        if (++i == 4) 
        {
            tet->map <<= map_size;
            i = 1; 
            tet->width = (tet->width < w) ? w : tet->width;
            w = 0;
        }
    }
    tet->next = NULL;
    return (tet);
}

/*static char     **save_fig_to_array(int fd)
{
    char *line;
    int i;
    char *figs[26]

    i = 0;
    *figs = (char*)malloc(sizeof(char));
    while (get_next_line(fd, &line)) 
    {
        i++;
        if ((ft_strlen(line) != 4) || (!sym_chk(line))) 
            print_error(2);
        if (((i % 5 == 0) && (!ft_strcmp(line,"/n"))) || (i / 5 >= 25)) 
            print_error(2);
        figs[(i - 1) / 5] = ft_strcat(figs[ (i - 1) / 5], line); 
    }
    return (&figs);
}*/

int figure_validation(int ac, char **av)
{
    tetramino   *fig;
    matrix_neg  matrix;
    int         map_size;
    int         i;
    int         fd;
    char        *fd_fig;
    char        *line;
    char        **figs[26];
    int         fig_counter;

    if (ac != 1)
        return (print_error(1));
    i = 0;
    if ((fd = open(av[1], O_RDONLY)) >= 3) 
        while (get_next_line(fd, &line)) 
        {
            i++;
            if ((ft_strlen(line) != 4) || (!sym_chk(line))) 
                return (print_error(2));
            if (((i % 5 == 0) && (!ft_strcmp(line,"/n"))) || (i / 5 >= 25)) 
                return (print_error(2));
            *figs[(i - 1) / 5] = ft_strcat(*figs[ (i - 1) / 5], line); 
        }
    fig_counter = (i - 1) / 5 + 1; 
    map_size = fig_counter; 
    while (fig_counter != 0)
    {
        if (val_chk(*figs[fig_counter])) 
            fig = fig_to_tet(*figs[fig_counter], map_size); 
        else
            return (print_error(2));
        fig_counter--; 
    }
    return (0);
}