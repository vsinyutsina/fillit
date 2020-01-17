#include "../includes/fillit.h"

int		shift_extended(t_tetramino *figure, t_border map_border)
{
    if (!(figure->map & map_border.right) 
    && !(figure->map_extended & map_border.right_ext))
    {
        figure->map_extended = (figure->map_extended >> 1) | (figure->map << 127);
        figure->map >>= 1;
    }
    else
    {
        figure->map_extended = (figure->map_extended >> figure->width) | (figure->map << (128 - figure->width));
        figure->map >>= figure->width;
    }
    return (figure->map_extended & map_border.bottom ? 0 : 1);
}

int		next_position_extended(t_tetramino *figure, t_border map_border,
		t_other_figures other_figures)
{

    if (figure->map == figure->map_begin
    && other_figures.last[figure->type])
    {
        figure->map = other_figures.last[figure->type];
        figure->map_extended = other_figures.last_extended[figure->type]; // in case figure was placed in the second map
    }
    while ((figure->map & other_figures.all) ||
    (figure->map_extended & other_figures.all_extended))
        if (!shift_extended(figure, map_border))
            return (0);
	return (1);
}

int		fill_figures_ext(t_tetramino *figure, t_border map_border,
		t_other_figures other_figures)
{
	int	next_figure;

	if (!figure)
		return (0);
	if (next_position_extended(figure, map_border, other_figures))
	{
		other_figures.last[figure->type] = figure->map;
        other_figures.last_extended[figure->type] = figure->map_extended;
		while ((next_figure = fill_figures_ext(figure->next, map_border,
				new_other_figures(other_figures, figure))))
		{
			if (next_figure == figure->type)
				return (next_figure);
			if (!shift_extended(figure, map_border))
				return (-1);
			other_figures.last[figure->type] = figure->map;
            other_figures.last_extended[figure->type] = figure->map_extended;
			if (!next_position_extended(figure, map_border, other_figures))
				return (-1);
			other_figures.last[figure->type] = figure->map;
            other_figures.last_extended[figure->type] = figure->map_extended;
			reset(figure->next);
		}
		return (0);
	}
	return (figure->type);
}