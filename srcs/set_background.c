#include "includes.h"
#include "struct.h"
#include "cub3d.h"

void	draw_square(int pos_x, int pos_y, int color, int size, t_data *data)
{
	int	x;
	int	y;

	x = pos_x;
	while (x < (pos_x + size))
	{
		y = pos_y;
		while (y < (pos_y + size))
		{
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
}



void	set_floor_and_ceiling(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < data->mlx.w_w)
	{
		y = 0;
		while (y < data->mlx.w_h)
		{
			if (y < data->mlx.w_h / 2)
				my_mlx_pixel_put(data, x, y, data->c_ceiling);
			else
				my_mlx_pixel_put(data, x, y, data->c_floor);
			y++;
		}
		x++;
	}
}
