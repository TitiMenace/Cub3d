
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

static int	hooks_handler(int zazou, t_data *data)
{
	if (zazou == XK_Escape)
	{
		destroy(data);
	}
	if (zazou == XK_w)
	{
		data->player_pos_x -= PLAYER_SPEED;	
	}
	if (zazou == XK_a)
	{
		data->player_pos_y -= PLAYER_SPEED;	
	}
	if (zazou == XK_d)
	{
		data->player_pos_y += PLAYER_SPEED;	
	}
	if (zazou == XK_s)
	{
		data->player_pos_x += PLAYER_SPEED;	
	}
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
