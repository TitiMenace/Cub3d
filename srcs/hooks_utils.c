
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	check_collision(t_data *data, int x, int y)
{
	if (data->map[x][y] != '0')
		return (true);
	else
		return (false);
}
