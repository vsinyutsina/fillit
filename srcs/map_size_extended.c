#include "../includes/fillit.h"

t_border			get_map_border_ext(int map_size)
{
	t_border	map_border;
	int		i;

	map_border.right = 1;
    map_border.right <<= 128 - map_size;
    
	i = 0;
	while (++i < map_size)
    {
        map_border.right_ext |= (map_border.right_ext >> map_size) | (map_border.right << (128 - map_size));
		map_border.right |= (map_border.right >> map_size);
    }
	map_border.bottom = -1;
	map_border.bottom >>= map_size * map_size - 128;
	return (map_border); 
}
