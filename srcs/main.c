
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	if (WIN_WIDTH <= 0 || WIN_HEIGHT <= 0)
	{
		destroy(data);
		return (false);
	}
	else
	{
		data->mlx.w_w = WIN_WIDTH;
		data->mlx.w_h = WIN_HEIGHT;
	}
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, \
			data->mlx.w_h, "cub3d");
	if (!data->mlx.win)
	{
		destroy(data);
		return (false);
	}
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	if (!data->img.img)
	{
		destroy(data);
		return (false);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bits_per_pixel, &data->img.line_lenght, \
			&data->img.endian);
	return (true);
}

bool	pos_y_p(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S')
		{
			data->player_pos_y = i + 0.5;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	parsing(t_data *data, char *map_name)
{
	data->map_start = 0;
	check_file_acces_open_file(map_name, data);
	block_a_getter_textures_colors(data);
	block_b_getter_array(data);
	come_back_to_block_b(data, map_name);
	duplicate_map(data);
	get_start_pos(data);
	//printf("%d height, %d line size , %f player pos x , %f player pos y\n	", data->map_height, data->line_size[0], data->player_pos_x, data->player_pos_y);
	if (!floodfill(data->map_copy, data->map_height, data->line_size, data->player_pos_x, data->player_pos_y, data->spawn_char))
	{
		printf("Error\nMap is invalid.");
		return (0);
	}
	return (1);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[y])
		{
			if (data->map[x][y] == '1')
				draw_square(y * 10, x * 10, 0xFF0000, 10, data);
			else
				draw_square( y * 10, x * 10, 0x00FF00, 10, data);
			y++;
		}
		x++;
	}
	draw_square(data->player_pos_y * 10 - 2, data->player_pos_x * 10 - 2, 0x0000FF, 5, data);
	
}


int	rendering(t_data *data)
{
	set_floor_and_ceiling(data);
	casting_ray(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	(void)ac;
	
	ft_bzero(&data, sizeof(t_data));
	init_parsing_resources(&data);
	if (!init_mlx(&data))
		return (0);
	if (!parsing(&data, av[1]))
		return (0);
//	clear_exit_parsing(&data, "TESTING LIGNE 115 MAIN");
	data.rs = 0.78539816339 / 2;
	data.speed = 0.40;
	data.plane_X = data.angle.vec_y;
	data.plane_Y = -data.angle.vec_x;
	mlx_loop_hook(data.mlx.mlx, rendering, &data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (1);
}
