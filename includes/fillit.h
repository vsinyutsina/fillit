//
// Created by Laurine Conchita on 24/11/2019.
//

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h> // DELETE

typedef struct  		tetramino_s
{
	__uint128_t			map;
	__uint128_t			map_begin;
	struct tetramino_s	*next;
	int					height;
	int					width;
	int					map_size;
	char				letter;
}						tetramino;

typedef struct			matrix_neg_s
{
	__uint128_t			right_border;
	__uint128_t			bottom_border;
	__uint128_t			negative;
}						matrix_neg;

tetramino				*get_tetramino(int fd, char letter);
int						get_map_size(tetramino *figure);
void					resize(tetramino *figure, int new_size);

void					print_fig(__uint128_t map, int map_size, char letter);
void					print_fig_param(tetramino *figure);
void					print_uint(__uint128_t line, int size, char l);

#endif
