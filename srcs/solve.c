#include "../includes/fillit.h"

int		next_position(t_tetramino *figure, t_border map_border)
{
	if (figure->map == figure->map_begin
	&& map_border.last_figure[figure->type])
		figure->map = map_border.last_figure[figure->type];
	while (figure->map & map_border.other_figures)
		if (!shift(figure, map_border))
			return (0);
	return (1);
}

int		shift(t_tetramino *figure, t_border map_border)
{
	if (!(figure->map & map_border.right))
		figure->map >>= 1;
	else
		figure->map >>= figure->width;
	return (figure->map & map_border.bottom ? 0 : 1);
}
