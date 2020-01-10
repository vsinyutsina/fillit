#include "fillit_start.h"
#include <stdio.h>

int     test(tetramino *fig, int map_size, __uint128_t negative)
{
    if (!fig)
    {
        print_map(negative, map_size);
        return (0);
    }
    while (negative & fig->map)
        fig->map >>= 1;
    negative = negative | fig->map;
    test(fig->next, map_size, negative);
    return (1);
}

void    on_map(tetramino *fig, int map_size)
{
    char    arr[map_size * (map_size + 1) + 1];
    size_t  i;
    char    alpha;

    i = 0;
    while (i < map_size * (map_size + 1))
    {
        if (((i + 1) % (map_size + 1)) == 0)
            arr[i] = '\n';
        else
            arr[i] = '.';
        i++;
    }
    arr[i] = '\0';
    alpha = 'A';
    while (fig)
    {
        i = 0;
        while (i < map_size * (map_size + 1))
        {
            if (((i + 1) % (map_size + 1)) == 0)
                i++;
            if (fig->map >> 127)
                arr[i] = alpha;
            fig->map <<= 1;
            i++;
        }
        fig = fig->next;
        alpha++;
    }
    ft_putstr(arr);
}

//
// created by laurine conchita on 24/11/2019.
//

