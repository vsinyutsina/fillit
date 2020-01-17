#include "../includes/fillit.h"
#include <stdio.h>

void	print_all(t_tetramino *figure, int params)
{
	if (!figure)
		return ;
	print(figure, params);
	print_all(figure->next, params);
}

void	print(t_tetramino *figure, int params)
{
	if (!figure)
		return ;
	print_fig(figure->map, figure->map_size, figure->letter);
	if (params)
		print_fig_param(figure);
	write(1, "\n", 1);
}

void	print_fig(__uint128_t map, int map_size, char letter)
{
	int				i;
	int				j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			if (map >> 127)
				write(1, &letter, 1);
			else
				write(1, ".", 1);
			write(1, " ", 1);
			map <<= 1;
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_fig_param(t_tetramino *figure)
{
	ft_putstr("size [w * h] = [");
	ft_putnbr(figure->width);
	ft_putstr(" * ");
	ft_putnbr(figure->height);
	ft_putstr("]\nmap size     = ");
	ft_putnbr(figure->map_size);
	ft_putstr("\ntype         = ");
	ft_putnbr(figure->type);
	write(1, "\n\n", 2);
}

void	print_uint(__uint128_t line, int size, char l)
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
