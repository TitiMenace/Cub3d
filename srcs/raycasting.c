
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	init_line(t_line *line, t_r_cast *values, t_data *data)
{
	line->lineHeight = (int)(data->mlx.w_h / values->perpWallDist);
	line->drawStart = -line->lineHeight / 2 + data->mlx.w_h / 2;
	if (line->drawStart < 0)
		line->drawStart = 0;
	line->drawEnd = line->lineHeight / 2 + data->mlx.w_h / 2;
	if (line->drawEnd >= data->mlx.w_h)
		line->drawEnd = data->mlx.w_h - 1;
}


void	init_var(t_r_cast *values, t_data *data, int x, int w)
{	
	values->cameraX = 2 * x / (double)w - 1;
	values->ray_dirX = data->angle.vec_x + data->plane_X * values->cameraX;
	values->ray_dirY = data->angle.vec_y + data->plane_Y * values->cameraX;
	if (!values->ray_dirX)
		values->delta_DistX = 1e30;
	else
		values->delta_DistX = fabs(1 / values->ray_dirX);
	if (!values->ray_dirY)
		values->delta_DistY = 1e30;
	else
		values->delta_DistY = fabs(1 / values->ray_dirY);
	values->map_x = (int)data->player_pos_x;
	values->map_y = (int)data->player_pos_y;
	


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
	(void)intersec;
	while (values->hit == 0)
	{
		if (values->sideDistX < values->sideDistY)
		{
			values->sideDistX += values->delta_DistX;
			values->map_x += values->stepX;
			data->side = 0;
		}
		else
		{
			values->sideDistY += values->delta_DistY;
			values->map_y += values->stepY;
			data->side = 1;
		}
		if (data->map[values->map_x][values->map_y] == '1')
			values->hit = 1;
	}
	if (data->side == 0)
	{
		values->perpWallDist = values->sideDistX - values->delta_DistX;
		values->intersec_x = data->player_pos_x + values->perpWallDist * cos(atan2(values->ray_dirY, values->ray_dirX));
		values->intersec_y = data->player_pos_y + values->perpWallDist * sin(atan2(values->ray_dirY, values->ray_dirX));
	}
	else
	{
		values->perpWallDist = values->sideDistY - values->delta_DistY;
		values->intersec_x = data->player_pos_x + values->perpWallDist * cos(atan2(values->ray_dirY, values->ray_dirX));
		values->intersec_y = data->player_pos_y + values->perpWallDist * sin(atan2(values->ray_dirY, values->ray_dirX));
	}
}

void	casting_ray(t_data *data, t_vec2 *intersec)
{
	t_r_cast	values;
	t_line	line;
	int	w = 1920;
	
	(void)intersec;
	for (int x = 0; x < w; x++)
	{
		init_var(&values, data, x, w);
		init_cast(&values, data);
		dda_alg(data, &values, intersec);
		init_line(&line, &values, data);
		draw_height_line(x, &line, data, &values);
	/*
		if (x > 950 && x < 970)
		{
			printf("coord x :%f y:%f ", intersec->x, intersec->y);
//			printf("this ray : deltaDistX is %f  deltaDistY is %f sidedistX is %f sidedistY is %f \n", values.delta_DistX, values.delta_DistY, values.sideDistX, values.sideDistY);
			printf("here line size is : %d && ray lenght is %f\n", line.lineHeight, values.perpWallDist);
		}
			*/
	}
//	usleep(5700);
}
