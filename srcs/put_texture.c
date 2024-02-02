
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
	int	i;

	(void)y;
	i = which_side(data, values);
	if (i == 0)
		return (0x00FF00);
	if (i == 1)
		return (0xFF0000);
	if (i == 2)
		return (0x0000FF);
	return (0xFFFF00);
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


