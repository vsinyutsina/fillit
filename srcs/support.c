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
	return (other_figures);
}

t_other_figures		get_other_figures(void)
{
	t_other_figures	new;
	int				i;

	new.all = 0;
	i = 0;
	while (i < 20)
		new.last[i++] = 0;
	return (new);
}
