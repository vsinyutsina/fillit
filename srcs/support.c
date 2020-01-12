#include "../includes/fillit.h"

void				get_type(t_tetramino *figure)
{
	t_tetramino		*tmp;
	size_t			max;

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
