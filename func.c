#include "fillit_start.h"
#include <stdio.h>

matrix_neg  save_borders(int map_size)
{
    matrix_neg  matrix;
    int         i;

    matrix.right_border = 1;
    matrix.right_border <<= 128 - map_size - 1;
    while (i++ < map_size)
        matrix.right_border = matrix.right_border | matrix.right_border >> map_size;
    matrix.bottom_border = -1;
    matrix.bottom_border >>= map_size * (map_size - 1) + 1;
    print_map(matrix.right_border, map_size);
    printf("%\n");
    print_map(matrix.bottom_border, map_size);
    printf("%\n");
    return(matrix);
}

int         shift(tetramino *fig, int map_size, __uint128_t right_border, __uint128_t bottom_border)
{
    if (!(fig->map & right_border))
    {
        fig->map >>= 1;
        print_map(fig->map, map_size);
        return (1);
    }
    if (!(fig->map & bottom_border))
    {
        fig->map >>= fig->width;
        print_map(fig->map, map_size);
        return (1);
    }
    print_map(fig->map, map_size);
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

int     print_error(int p) //вывод текста ошибки
{
    if (p == 1)
        ft_putstr("usage: ./fillit source_file");
    if (p == 2)
        ft_putstr("error");
    return (0) ;
}

int         sym_chk(char *line) //проверка что среди символов только '.' и '#'
{
    while (line)
        if (*line == '.' || *line == '#')
            line++;
        else
            return (0);
        return (1);
}

tetramino   *fig_to_tet(char *pos_f, int map_size) //конвертирует фигуру из 16 символов в 128 бит с учетом размера карты + подсчет ширины
{
    int         i; //счетчик бит внутри квартала // (начальная фигура состоит из 4 кварталов по 4 бита)
    int         w; //счетчик ширины фигуры
    tetramino   *tet; //результат

    i = 1;
    w = 0;
    tet->map = 0; //начальная карта тетрамина - 128 нулей
    while (pos_f) //идем по фигуре
    {
        if (*pos_f == '#') //если встречаем решетку
        {
            w++; //увеличиваем счетчик ширины
            tet->map =+ 1; //прибавлем к карте 1 (0..001)
        }
        tet->map <<= 1; // сдвиг влево
        i++;
        if (i == 4) //если квартал закончился (16 знаков делятся по 4)
        {
            while (map_size--) //сдвиг дополнительно влево на размер карты
                tet->map <<= 1;
            i = 1; //сбрасываем счетчик бит внутри квартала
            if (tet->width < w) //если текущая ширина больше найденной из пройденных ранее кварталов
                tet->width = w; //сохраняем текущую как максимальную
            w = 0;
        }
    }
    tet->next = NULL;
    return (tet);
}

int         val_chk(char *pos_f) //проверка валидности фигуры (16-символьная строка)
{
    int k;

    k = 0;
    while (pos_f++)
    {
        if ((*pos_f == '#') && ((*(pos_f >> 1) == '#') || (*(pos_f >> 8) == '#'))) //считаем связи вправо-вниз
            k++;
    }
    while (pos_f--)
    {
        if ((*pos_f == '#') && ((*(pos_f << 1) = '#') || (*(pos_f << 8) = '#'))) //считаем связи влево-вверх
            k++;
    }
    if ((k == 8) || (k == 6)) // 8 для Г-шки, 6 для всех остальных
        return (1);
    return (0);
}
//
// Created by Laurine Conchita on 24/11/2019.
//

