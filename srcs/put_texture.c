
#include "includes.h"
#include "cub3d.h"
#include "struct.h"


int get_color(double y, t_data *data, t_r_cast *values, t_texture *texture)
{
	double wallX;
	int color;
	if (data->side == 0)
		wallX = data->player_pos_y + values->perpWallDist * values->ray_dirY;
	else
		wallX = data->player_pos_x + values->perpWallDist * values->ray_dirX;
	wallX = fmod(wallX, 1);
	if (data->side == 0 && values->ray_dirX > 0)
		wallX = 1 - wallX;
	if (data->side == 1 && values->ray_dirY < 0)
		wallX = 1 - wallX; 
	color = 255 * wallX;
	color <<= 8;
	color += 255 * y;

	int texture_x = (int)(wallX * (double)texture->width);
	int texture_y = (int)(y * (double)texture->length);
	

	color = texture->img.addr[texture_y * texture->img.line_lenght + texture_x * (texture->img.bits_per_pixel / 8)] + 
		texture->img.addr[texture_y * texture->img.line_lenght + texture_x * (texture->img.bits_per_pixel / 8) + 1] * 256 +
		texture->img.addr[texture_y * texture->img.line_lenght + texture_x * (texture->img.bits_per_pixel / 8) + 2] * 256 * 256;
//	dprintf(2, "couleur : %d\n", color);
	return (color);
}


void    draw_height_line(int x, t_line    *line, t_data *data, t_r_cast *values)
{
	double    i;

	i =  line->drawStart;
	while (i < line->drawEnd)
	{
		//	printf("i = %f\n", i);
		// printf("line->drawStart = %d, line->drawEnd = %d\n", line->drawStart, line->drawEnd);
		// printf("y = %f\n", (i - line->drawStart) / line->lineHeight);
		if (data->side && values->ray_dirY > 0)
		{
//			dprintf(2, "taille de la text ea%d\n", data->ea_texture.width);
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->ea_texture));
		}
		else if (data->side && values->ray_dirY < 0)
		{
	
//			dprintf(2, "taille de la text we%d\n", data->we_texture.width);
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->we_texture));
		}
		else if (!data->side && values->ray_dirX > 0)
		{
	//		dprintf(2, "taille de la text so :%d\n", data->so_texture.width);
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->so_texture));    
		}
		else
		{
//			dprintf(2, "taille de la text no %d\n", data->no_texture.width);
			my_mlx_pixel_put(data, x, i, get_color((i - line->drawStart) / line->lineHeight, data, values, &data->no_texture));
		}
		i++;
	}
}
