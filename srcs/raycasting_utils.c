/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:04:55 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 17:12:50 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	init_distance(t_data *data, t_r_cast *values)
{
	if (data->side == 0)
	{
		values->perpWallDist = values->sideDistX - values->delta_DistX;
		values->intersec_x = data->player_pos_y + values->perpWallDist
			* values->ray_dirY;
		values->intersec_y = values->map_y;
	}
	else
	{
		values->perpWallDist = values->sideDistY - values->delta_DistY;
		values->intersec_y = data->player_pos_x + values->perpWallDist
			* values->ray_dirX;
		values->intersec_x = values->map_x;
	}
}
