#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h> // DELETE

# define ABS(x) ((x) < 0 ? -(x) : (x))
# define MAX(a, b) (a > b ? a : b)

typedef struct			s_tetramino
{
	__uint128_t			map;
	__uint128_t			map_extended;
	__uint128_t			map_begin;
	int					map_size;
	int					width;
	int					height;
	int					type;
	char				letter;
	struct s_tetramino	*next;
}						t_tetramino;

typedef struct			s_border
{
	__uint128_t			right;
	__uint128_t			bottom;
	__uint128_t			other_figures;
	__uint128_t			last_figure[20];
}						t_border;

t_tetramino				*init_tetramino(int fd, char letter);
int						get_map_size(t_tetramino *figure);
void					resize(t_tetramino *figure, int new_size);
t_border					get_map_border(int map_size);
void					get_type(t_tetramino *figure);

int						shift(t_tetramino *figure, t_border map_border);
int						next_position(t_tetramino *figure, t_border map_border);

void					print_fig(__uint128_t map, int map_size, char letter);
void					print_fig_param(t_tetramino *figure);
void					print_uint(__uint128_t line, int size, char l);
void					print(t_tetramino *figure, int params);
void					print_all(t_tetramino *figure, int params);

#endif
