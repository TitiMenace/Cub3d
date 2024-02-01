
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

int	which_side(t_data *data, t_r_cast *values)
{
	if (data->side && values->ray_dirY > 0)
		return (0);
	else if (data->side && values->ray_dirY < 0)
		return (1);
	else if (!data->side && values->ray_dirX > 0)
		return (2);
	return (3);
}

char	*get_sprite(int nb, t_data *data)
{
	if (!nb)
		return (data->ea_texture.data);
	if (nb == 1)
		return (data->we_texture.data);
	if (nb == 2)
		return (data->so_texture.data);
	return (data->no_texture.data);
}

int	get_color(double y, t_data *data, t_r_cast *values)
{
	float			wall_x;
	unsigned long	tex_x;

	if (!data->side)
		wall_x = data->player_pos_y + values->perpWallDist * values->ray_dirY;
	else
		wall_x = data->player_pos_x + values->perpWallDist * values->ray_dirX;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * 512);
	if ((!data->side && values->ray_dirX > 0) || \
			(data->side && values->ray_dirY < 0))
		tex_x = 512 - tex_x - 1;
	return (get_sprite(which_side(data, values), data)[(int)y][tex_x]);
}


void	draw_height_line(int x, t_line	*line, t_data *data, t_r_cast *values)
{
	double	i;

	i =  line->drawStart;
	while (i < line->drawEnd)
	{
		my_mlx_pixel_put(data, x, i, get_color(i, data, values));
		i++;
	}



}


