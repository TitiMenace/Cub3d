/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:07:00 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/13 19:28:14 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	parsing(t_data *data, char *map_name)
{
	check_file_acces_open_file(map_name, data);
	if (!block_a_getter_textures_colors(data))
	{
		printf("Error\nMap is invalid.\n");
		return (0);
	}
	if (!block_b_getter_array(data))
	{
		printf("c'est wuuu\n");
		printf("Error\nMap is invalid.\n");
		return (0);
	}
	come_back_to_block_b(data, map_name);
	duplicate_map(data);
	get_start_pos(data);
	if (!floodfill(data, data->player_pos_x, data->player_pos_y))
	{
		printf("Error\nMap is invalid.\n");
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

static void	xy_swap(t_data *data)
{
	float	x;

	x = data->player_pos_y;
	data->player_pos_y = data->player_pos_x;
	data->player_pos_x = x;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (0);
	ft_bzero(&data, sizeof(t_data));
	init_parsing_resources(&data);
	if (!init_mlx(&data))
		return (0);
	if (!parsing(&data, av[1]))
	{
		clear_exit_parsing(&data, "");
		return (0);
	}
	data.mlx.win = mlx_new_window(data.mlx.mlx, data.mlx.w_w, \
			data.mlx.w_h, "cub3d");
	if (!data.mlx.win)
	{
		destroy(&data);
		return (false);
	}
	xy_swap(&data);
	data.rs = 0.78539816339 / 2;
	data.speed = 0.40;
	data.plane_x = data.angle.vec_y;
	data.plane_y = -data.angle.vec_x;
	mlx_loop_hook(data.mlx.mlx, rendering, &data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
	return (1);
}
