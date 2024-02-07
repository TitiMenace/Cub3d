/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:07:00 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 19:08:46 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	init_img(t_data *data)
{
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
	if (!init_img(data))
		return (false);
	return (true);
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
	if (!floodfill(data->map_copy, data->map_height, data->line_size, data->player_pos_x, data->player_pos_y, data->spawn_char))
	{
		printf("Error\nMap is invalid.");
		return (0);
	}
	return (1);
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
	
	if (ac != 2)
		return(0);
	ft_bzero(&data, sizeof(t_data));
	init_parsing_resources(&data);
	if (!init_mlx(&data))
		return (0);
	if (!parsing(&data, av[1]))
	{
		clear_exit_parsing(&data, "");
		return (0);
	}
	float x = data.player_pos_y;
	data.player_pos_y = data.player_pos_x;
	data.player_pos_x = x;
	data.rs = 0.78539816339 / 2;
	data.speed = 0.40;
	data.plane_X = data.angle.vec_y;
	data.plane_Y = -data.angle.vec_x;
	mlx_loop_hook(data.mlx.mlx, rendering, &data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (1);
}
