/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:02:35 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/07 18:13:53 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	set_wallx(double *wallx, t_data *data, t_r_cast *values)
{
	if (data->side == 0)
		*wallx = data->player_pos_y + values->perpWallDist * values->ray_dirY;
	else
		*wallx = data->player_pos_x + values->perpWallDist * values->ray_dirX;
	*wallx = fmod(*wallx, 1);
	if (data->side == 0 && values->ray_dirX > 0)
		*wallx = 1 - *wallx;
	if (data->side == 1 && values->ray_dirY < 0)
		*wallx = 1 - *wallx;
}

int	get_color(double y, t_data *data, t_r_cast *values, t_texture *texture)
{
	double	wallx;
	int		color;
	int		texture_x;
	int		texture_y;

	set_wallx(&wallx, data, values);
	color = 255 * wallx;
	color <<= 8;
	color += 255 * y;
	texture_x = (int)(wallx * (double)texture->width);
	texture_y = (int)(y * (double)texture->length);
	color = texture->img.addr[texture_y * texture->img.line_lenght + texture_x
		* (texture->img.bits_per_pixel / 8)]
		+ texture->img.addr[texture_y * texture->img.line_lenght + texture_x
		* (texture->img.bits_per_pixel / 8) + 1] * 256
		+ texture->img.addr[texture_y * texture->img.line_lenght + texture_x
		* (texture->img.bits_per_pixel / 8) + 2] * 256 * 256;
	return (color);
}

void	draw_height_line(int x, t_line *line, t_data *data, t_r_cast *values)
{
	double	i;

	i = line->drawStart;
	while (i < line->drawEnd)
	{
		if (data->side && values->ray_dirY > 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart)
					/ line->lineHeight, data, values, &data->ea_texture));
		else if (data->side && values->ray_dirY < 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart)
					/ line->lineHeight, data, values, &data->we_texture));
		else if (!data->side && values->ray_dirX > 0)
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart)
					/ line->lineHeight, data, values, &data->so_texture));
		else
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart)
					/ line->lineHeight, data, values, &data->no_texture));
		i++;
	}
}
