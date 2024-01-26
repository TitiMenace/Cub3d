
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

int	**get_sprite(int nb, t_data *data)
{
	if (!nb)
		return (data->ea_texture);
	if (nb == 1)
		return (data->we_texture);
	if (nb == 2)
		return (data->so_texture);
	return (data->no_texture);
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
	
	int		i;
	double	j;
	double	img_step;
	int len;

	i = 0;
	j = 0;
	len = line->lineHeight;
	img_step = (double)512.0 / (double)len;
	j = img_step / 2;
	while (i < len)
	{
		my_mlx_pixel_put(data, x, data->mlx.w_h / 2 - (len / 2) + i, get_color(j, data, values));
		i++;
		j += img_step;
	}
}


