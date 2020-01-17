#include "../includes/fillit.h"

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

int		shift_extended(t_tetramino *figure, t_border map_border)
{
    __uint128_t tmp;

    if (figure->map_size >= 12 && !figure->map_extended)
    {
        tmp = figure->map;
        tmp <<= 128 - figure->width;
        figure->map_extended = tmp;
        figure->map >>= figure->width;
    }
    if (figure->map)
    {
//        figure->map >>= figure->map & map_border.right ? figure->width : 1;
      if (!(figure->map & map_border.right))
        figure->map >>= 1;
      else
        figure->map >>= figure->width;
    }
    if (figure->map_extended)
    {
        if (!(figure->map_extended & map_border.right))
            figure->map_extended >>= 1;
        else 
            figure->map_extended >>= figure->width;
    }
	return (figure->map_extended & map_border.bottom ? 0 : 1);
}

void	reset(t_tetramino *figure)
{
	if (!figure)
		return ;
	figure->map = figure->map_begin;
    figure->map_extended = 0;
	reset(figure->next);
}

int		fill_figures(t_tetramino *figure, t_border map_border,
		t_other_figures other_figures)
{
	int	next_figure;

	if (!figure)
		return (0);
	if (next_position(figure, map_border, other_figures))
	{
		other_figures.last[figure->type] = figure->map;
		while ((next_figure = fill_figures(figure->next, map_border,
				new_other_figures(other_figures, figure))))
		{
			if (next_figure == figure->type)
				return (next_figure);
			if (!shift(figure, map_border))
				return (-1);
			other_figures.last[figure->type] = figure->map;
            other_figures.last_extended[figure->type] = figure->map_extended;
			if (!next_position(figure, map_border, other_figures))
				return (-1);
			other_figures.last[figure->type] = figure->map;
            other_figures.last_extended[figure->type] = figure->map_extended;
			reset(figure->next);
		}
		return (0);
	}
	return (figure->type);
}