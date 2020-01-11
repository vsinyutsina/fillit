//
// Created by Fredia Wiley on 11/01/2020.
//

#include "../includes/fillit.h"

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
//	ft_putstr("map size = ");
//	ft_putnbr(figure->map_size);
//	ft_putstr("\nheight   = ");
//	ft_putnbr(figure->height);
//	ft_putstr("\nwidth    = ");
//	ft_putnbr(figure->width);
	write(1, "\n", 1);
}

void	print_fig_param(tetramino *figure)
{
	ft_putstr("map size = ");
	ft_putnbr(figure->map_size);
	ft_putstr("\nheight   = ");
	ft_putnbr(figure->height);
	ft_putstr("\nwidth    = ");
	ft_putnbr(figure->width);
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
