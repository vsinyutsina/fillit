//
// Created by Laurine Conchita on 24/11/2019.
//

#ifndef FILLIT_START_H
# define FILLIT_START_H
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct  		tetramino_s
{
	__uint128_t			map;
	struct tetramino_s	*next;
	int					width;
	char				letter;
}						tetramino;

typedef struct			matrix_neg_s
{
	__uint128_t			right_border;
	__uint128_t			bottom_border;
	__uint128_t			negative;
}						matrix_neg;


int						print_error(int p);
tetramino				*get_tetramino(int fd, char letter);

#endif
