#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

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
	__uint128_t			right_ext;
	__uint128_t			bottom;
}						t_border;

typedef struct			s_other_figures
{
	__uint128_t			all;
	__uint128_t			all_extended;
	__uint128_t			last[20];
	__uint128_t			last_extended[20];
}						t_other_figures;

t_tetramino				*init_tetramino(int fd, char letter);
int						get_map_size(t_tetramino *figure);
void					resize(t_tetramino *figure, int new_size);
t_border				get_map_border(int map_size);
void					get_type(t_tetramino *figure);
void					free_figures(t_tetramino *figure);
t_other_figures			get_other_figures(void);
int						fill_figures(t_tetramino *figure, t_border map_border,
						t_other_figures other_figures);

int						shift(t_tetramino *figure, t_border map_border);
int						next_position(t_tetramino *figure, t_border map_border,
						t_other_figures other_figures);
t_other_figures			new_other_figures(t_other_figures other_figures,
						t_tetramino *figure);
void					reset(t_tetramino *figure);

void					print_fig(__uint128_t map, int map_size, char letter);
void					print_fig_param(t_tetramino *figure);
void					print_uint(__uint128_t line, int size, char l);
void					print(t_tetramino *figure, int params);
void					print_all(t_tetramino *figure, int params);

void					print_map(t_tetramino *figure);
t_border				get_map_border_ext(int map_size);
int						shift_extended(t_tetramino *figure, t_border map_border);
int						next_position_extended(t_tetramino *figure, t_border map_border,
						t_other_figures other_figures);
int						fill_figures_ext(t_tetramino *figure, t_border map_border,
						t_other_figures other_figures);

#endif
