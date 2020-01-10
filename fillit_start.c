#include <stdio.h>
#include "fillit_start.h"

tetramino   *test_map(int map_size, int type_fig)
{
    tetramino   *map_start;

    if (!(map_start = (tetramino*)malloc(sizeof(tetramino))))
        return (NULL);
    if (type_fig == 3)
    {
        map_start->map = 3;
        map_start->map <<= map_size;
        map_start->map += 3;
        map_start->map <<= 128 - map_size - 2;
        map_start->width = 2;
    }
    if (type_fig == 1)
    {
        map_start->map = 1;
        map_start->map <<= map_size;
        map_start->map += 1;
        map_start->map <<= map_size;
        map_start->map += 1;
        map_start->map <<= map_size;
        map_start->map += 1;
        map_start->map <<= 128 - map_size * 3 - 1;
        map_start->width = 1;
    }
    if (type_fig == 2)
    {
        map_start->map = 1;
        map_start->map <<= map_size;
        map_start->map += 1;
        map_start->map <<= map_size;
        map_start->map += 3;
        map_start->map <<= map_size;
        map_start->map <<= 128 - map_size * 4 + 5;
        map_start->width = 2;
    }
    if (type_fig == 4)
    {
        map_start->map = 2;
        map_start->map <<= map_size;
        map_start->map += 7;
        //map_start->map <<= map_size;
        map_start->map <<= 128 - map_size - 3;
        map_start->width = 3;
    }
    map_start->next = NULL;
    return (map_start);
}

void        print_map(__uint128_t map, int map_size)
{
    __uint128_t copy;
    int         map_size_1;
    int         map_size_2;

    copy = map;
    //print_uint(map, 127, '#');
    //printf("%d\n", 1);
    copy <<= 1;
    //print_uint(copy, 127, '#');
    //printf("%d\n", 2);
    map_size_1 = map_size;
    //map_size_2 = map_size;
    while (map_size_1)
    {
        map_size_2 = map_size;
        while (map_size_2)
        {
            if (copy >> 127)
                ft_putstr("# ");
            else
                ft_putstr(". ");
            copy <<= 1;
            map_size_2--;
        }
        ft_putchar('\n');
        map_size_1--;
    }
}

int main(int ac, char **av)
{
    tetramino   *fig;
    tetramino   *tmp;
    tetramino   *tmp2;
    __uint128_t negative;
    matrix_neg  matrix;
    int         map_size;
    int         i = 0;
    int         fd;
    char        *fd_fig;
    char        *line;
    char        **figs[26];
    int         fig_counter;

/*  map_size = 6;
    negative = 0;

    fig = test_map(map_size, 4);
    print_uint(fig->map, 127, '#');
    ft_putchar('\n');
/*
     tmp = fig;
     tmp2 = fig;
     tmp->next = test_map(4, 1);
     tmp = tmp->next;
     tmp->next = test_map(4, 1);
     tmp = tmp->next;
     test(fig, 4, negative);


     while (tmp2 != NULL)
     {
        print_map(tmp2->map, 4);
        tmp2 = tmp2->next;
        ft_putchar('\n');
     }*/
    if (ac != 1)
        return (print_error(1));
    i = 0;
    if ((fd = open(av[1], O_RDONLY)) >= 3) //открываем файл фигур
        while (get_next_line(fd, &line)) //считываем строку из файла пока считывается
        {
            i++;
            if ((ft_strlen(line) != 4) || (!sym_chk(line))) //проверка что в строке 4 валидных символ
                return (print_error(2));
            if (((i % 5 == 0) && (!ft_strcmp(line,"/n"))) || (i / 5 >= 25)) //проверка /n в каждой 5-ой строке и не более 26 фигур
                return (print_error(2));
            *figs[(i - 1) / 5] = ft_strcat(*figs[ (i - 1) / 5], line); //запись фигуры в массив в виде 16-символьной строки
        }
    fig_counter = (i - 1) / 5 + 1; //количество фигур в файле
    map_size = fig_counter; //пока так, после надо высчитать размер карты по формуле
    while (fig_counter != 0)
    {
        if (val_chk(*figs[fig_counter])) //если фигура валидна
            fig = fig_to_tet(*figs[fig_counter], map_size); //конвертация фигуры в тетрамин
        else
            return (print_error(2));
        fig_counter--; //идем с конца массива чтобы использовать одну переменную
    }

    matrix = save_borders(map_size);
    while (shift(fig, map_size, matrix.right_border, matrix.bottom_border) && i < 12)
    {
        //print_map(fig->map, map_size);
        ft_putchar('\n');
        i++;
    }
    return (0);
}
