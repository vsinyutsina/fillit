#include "../includes/fillit.h"

void				get_type(t_tetramino *figure)
{
	t_tetramino		*tmp;
	int				max;

	if (figure)
	{
		get_type(figure->next);
		tmp = figure->next;
		max = 0;
		while (tmp && !figure->type)
		{
			if (figure->map == tmp->map)
				figure->type = tmp->type;
			max = MAX(max, tmp->type);
			tmp = tmp->next;
		}
		if (!figure->type)
			figure->type = max + 1;
	}
}

void				free_figures(t_tetramino *figure)
{
	if (!figure)
		return ;
	free_figures(figure->next);
	free(figure);
	figure = NULL;
}

t_other_figures		new_other_figures(t_other_figures other_figures,
					t_tetramino *figure)
{
	other_figures.all |= figure->map;
	other_figures.all_extended |= figure->map_extended;
	return (other_figures);
}

t_other_figures		get_other_figures(void)
{
	t_other_figures	new;
	int				i;

	new.all = 0;
	i = 0;
	while (i < 20)
	{
		new.last[i] = 0;
		new.last_extended[i++] = 0;
	}
	return (new);
}

void				print_map(t_tetramino *figure)
{
	char			array[figure->map_size * (figure->map_size + 1)];
	t_tetramino		*tmp;
	int				i;

	i = -1;
	tmp = figure;
	while (i++ < figure->map_size * (figure->map_size + 1))
		array[i] = (i + 1) % (figure->map_size + 1) ? '.' : '\n';
	while (tmp)
	{
		i = 0;
		while (i < (tmp->map_size * (tmp->map_size + 1)))
		{
			if ((i + 1) % (tmp->map_size + 1))
			{
				if (tmp->map >> 127)
					array[i] = tmp->letter;
				tmp->map = (tmp->map << 1) | (tmp->map_extended >> 127);
				tmp->map_extended <<= 1;
			}
			i++;
		}
		tmp = tmp->next;
	}
	write(1, array, figure->map_size * (figure->map_size + 1));
}
