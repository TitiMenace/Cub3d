#include "cub3d.h"
#include "struct.h"
#include "includes.h"

static void	get_pos_direction(t_data *data, char pos)
{
	if (pos == 'E')
	{
		data->angle.vec_x = 0;
		data->angle.vec_y = 1;
	}
	if (pos == 'N')
	{
		data->angle.vec_x = -1;
		data->angle.vec_y = 0;
	}
	if (pos == 'W')
	{
		data->angle.vec_x = 0;
		data->angle.vec_y = -1;
	}
	if (pos == 'S')
	{
		data->angle.vec_x = 1;
		data->angle.vec_y = 0;
	}
}

void	get_start_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->spawn = 0;
	while (y < data->map_height)
	{
		while (x < data->line_size[y])
		{
			if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
			{
				data->spawn++;
				data->player_pos_x = x + 0.5;
				data->player_pos_y = y + 0.5;
				get_pos_direction(data, data->map[y][x]);
				data->spawn_char = data->map[y][x];
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (data->spawn != 1)
	{
		printf("Error\nOnly one spawn point accepted.");
		clear_exit_parsing(data, "");
	}
}

bool	floodfill(char **map, int map_height, int *line_size, int x, int y, char spawn_char)
{
	if (x < 0 || x >= line_size[y] || y < 0 || y >= map_height \
	|| map[y][x] == '1')
		return (1);
	if (map[y][x] != '0' && map[y][x] != spawn_char)
		return (0);
	map[y][x] = '1';
	if (!floodfill(map, map_height, line_size, x + 1, y, spawn_char))
		return (0);
	if (!floodfill(map, map_height, line_size, x - 1, y, spawn_char))
		return (0);
	if (!floodfill(map, map_height, line_size, x, y + 1, spawn_char))
		return (0);
	if (!floodfill(map, map_height, line_size, x, y - 1, spawn_char))
		return (0);
	return (1);
}
