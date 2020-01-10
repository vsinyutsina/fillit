//
// Created by Laurine Conchita on 24/11/2019.
//

#ifndef FILLIT_START_H
# define FILLIT_START_H
# include "libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct  tetramino_s
{
    __uint128_t         map;
    struct tetramino_s  *next;
    int                 width;
}               tetramino;

typedef struct  matrix_neg_s
{
    __uint128_t         right_border;
    __uint128_t         bottom_border;
    __uint128_t         negative;
}               matrix_neg;

tetramino       *test_map(int map_size, int type_fig);
void            print_map(__uint128_t map, int map_size);
int             shift(tetramino *fig, int map_size, __uint128_t right_border, __uint128_t bottom_border);
int             test(tetramino *fig, int map_size, __uint128_t negative);
void            on_map(tetramino *fig, int map_size);
matrix_neg      save_borders(int map_size);
void            print_uint(__uint128_t line, int size, char l);
int             val_chk(char *pos_f);
int             sym_chk(char *line);
tetramino       *fig_to_tet(char *pos_fig, int fig_counter);
int             print_error(int p);

#endif //UNTITLED_FILLIT_START_H
