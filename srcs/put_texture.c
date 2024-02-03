
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

int	get_color(double y, t_data *data, t_r_cast *values, t_texture *texture)
{
	double	wallX;
	double	wallY;
	int		color;

	if (data->side == 0)
		wallX = fmod(values->intersec_y, 1);
	else
		wallX = fmod(values->intersec_x, 1);
	wallX *= texture->width;
	wallY = y * texture->length;
	color = *(int *)texture->img.addr + texture->width * wallY + wallX;
	return (color);
}


void	draw_height_line(int x, t_line	*line, t_data *data, t_r_cast *values)
{
	double	i;

	i =  line->drawStart;
	while (i < line->drawEnd)
	{
		if (data->side && values->ray_dirY > 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->ea_texture));
		if (data->side && values->ray_dirY < 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->we_texture));
		if (!data->side && values->ray_dirX > 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->so_texture));
		else	
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->no_texture));
		i++;
	}
}


