
#include "includes.h"
#include "cub3d.h"
#include "struct.h"


void	init_var(t_r_cast *values, t_data *data, int x, int w)
{	
	values->cameraX = 2 * x / (double)w - 1;
	values->ray_dirX = data->angle.vec_x + data->plane_X * values->cameraX;
	values->ray_dirY = data->angle.vec_y + data->plane_Y * values->cameraX;
	values->map_x = (int)data->player_pos_x;
	values->map_y = (int)data->player_pos_y;
	values->delta_DistX = sqrt(1 + (values->ray_dirY * values->ray_dirY) / (values->ray_dirX * values->ray_dirX));
	values->delta_DistY = sqrt(1 + (values->ray_dirX * values->ray_dirX) / (values->ray_dirY * values->ray_dirY));
	values->hit = 0;
}

void	init_cast(t_r_cast *values, t_data *data)
{
	 if (values->ray_dirX < 0)
	 {
		values->stepX = -1;
		values->sideDistX = (data->player_pos_x - values->map_x) * values->delta_DistX;
	 }
	 else
	 {
		 values->stepX = 1;
		 values->sideDistX = (values->map_x + 1.0 - data->player_pos_x) * values->delta_DistX;
	 }
	 if (values->ray_dirY < 0)
	 {
		values->stepY = -1;
		values->sideDistY = (data->player_pos_y - values->map_y) * values->delta_DistY;
	 }
	 else
	 {
		 values->stepY = 1;
		 values->sideDistY = (values->map_y + 1.0 - data->player_pos_y) * values->delta_DistY;
	 }
}
void	dda_alg(t_data *data, t_r_cast *values, t_vec2	*intersec)
{
	while (values->hit == 0)
	{
		if (values->sideDistX < values->sideDistY)
		{
			values->sideDistX += values->delta_DistX;
			values->map_x += values->stepX;
		}
		else
		{
			values->sideDistY += values->delta_DistY;
			values->map_y += values->stepY;
		}
		if (data->map[values->map_x][values->map_y] > 0)
			values->hit = 1;
	}
	intersec->x = values->map_x;
	intersec->y = values->map_y;
}


void	casting_ray(t_data *data, t_vec2 *intersec)
{
	t_r_cast	values;
	int	w = 1920;

	for (int x = 0; x < w; x++)
	{
		init_var(&values, data, x, w);
		init_cast(&values, data);
		dda_alg(data, &values, intersec);
		draw_square(intersec->x, intersec->y, 0xffffff, 10, data);
	}

}
