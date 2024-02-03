
#include "cub3d.h"
#include "includes.h"
#include "struct.h"

int	destroy(t_data *data)
{
	if (data->img.img)
		mlx_destroy_image(data->mlx.mlx, data->img.img);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
	}
	exit(1);
	return (1);
}

void	up_down_hook(int keycode, t_data *data)
{
	if (keycode == 119)
	{
		if (data->map[(int)(data->player_pos_x + data->angle.vec_x * \
					(data->speed * 2))][(int)(data->player_pos_y)] == '0')
		{
			data->player_pos_x += data->angle.vec_x * data->speed;
		}
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y \
					+ data->angle.vec_y * (data->speed * 2))] == '0')
		{
			data->player_pos_y += data->angle.vec_y * data->speed;
		}
	}
	if (keycode == 115)
	{
		if (data->map[(int)(data->player_pos_x - data->angle.vec_x * (data->speed * \
						2))][(int)(data->player_pos_y)] == '0')
			data->player_pos_x -= data->angle.vec_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y - \
					data->angle.vec_y * (data->speed * 2))] == '0')
			data->player_pos_y -= data->angle.vec_y * data->speed;
	}
}

void	right_hook(int keycode, t_data *data)
{
	float	v_orth_x;
	float	v_orth_y;

	if (keycode == 97)
	{
		v_orth_x = -data->angle.vec_y;
		v_orth_y = data->angle.vec_x;
		if (data->map[(int)(data->player_pos_x + v_orth_x * (data->speed * 2))][(int)(data->player_pos_y)] == '0')
			data->player_pos_x += v_orth_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y + v_orth_y * (data->speed * 2))] == '0')
			data->player_pos_y += v_orth_y * data->speed;
	}
}

void	left_hook(int keycode, t_data *data)
{
	float	v_orth_x;
	float	v_orth_y;

	if (keycode == 100)
	{
		v_orth_x = data->angle.vec_y;
		v_orth_y = -data->angle.vec_x;
		if (data->map[(int)(data->player_pos_x + v_orth_x * (data->speed * 2))][(int)(data->player_pos_y)] == '0')
			data->player_pos_x += v_orth_x * data->speed;
		if (data->map[(int)(data->player_pos_x)][(int)(data->player_pos_y + v_orth_y * (data->speed * 2))] == '0')
			data->player_pos_y += v_orth_y * data->speed;
	}
}

void	pan_hook(int keycode, t_data *data)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->angle.vec_x;
	old_plane_x = data->plane_X;
	if (keycode == 65363)
	{
		data->angle.vec_x = data->angle.vec_x * cos(-data->rs) - data->angle.vec_y * sin(-data->rs);
		data->angle.vec_y = old_dir_x * sin(-data->rs) + data->angle.vec_y * cos(-data->rs);
		data->plane_X = data->plane_X * cos(-data->rs) - data->plane_Y * sin(-data->rs);
		data->plane_Y = old_plane_x * sin(-data->rs) + data->plane_Y * cos(-data->rs);
	}
	if (keycode == 65361)
	{
		data->angle.vec_x = data->angle.vec_x * cos(data->rs) - data->angle.vec_y * sin(data->rs);
		data->angle.vec_y = old_dir_x * sin(data->rs) + data->angle.vec_y * cos(data->rs);
		data->plane_X = data->plane_X * cos(data->rs) - data->plane_Y * sin(data->rs);
		data->plane_Y = old_plane_x * sin(data->rs) + data->plane_Y * cos(data->rs);
	}
}

static int	hooks_handler(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
	{
		destroy(data);
	}
	up_down_hook(keycode, data);
	right_hook(keycode, data);
	left_hook(keycode, data);
	pan_hook(keycode, data);
	return (1);
}

int	cross_button(t_data *data)
{
	destroy(data);
	return (1);
}

void	init_hooks(t_data *data)
{
	mlx_hook(data->mlx.win, 17, (1L << 17), cross_button, data);
	mlx_hook(data->mlx.win, 2, KeyPressMask, hooks_handler, data);
}
