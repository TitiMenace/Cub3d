
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

	(void)y;
	if (data->side == 0)
	{
		dprintf(3, "data->intersec_x %f\n intersec_y : %f\n ", values->intersec_x, values->intersec_y);
	}
	return (1);
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


