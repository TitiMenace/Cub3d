/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:24:53 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/03 11:38:10 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"

void	block_a_checker_open_path(char *line, t_data *data, t_texture *texture)
{
	char	*filename;
//	int		x;
//	int		y;

	
	filename = ft_get_textures_name(line + utils_skip_spaces(line)); //moove the offset of line too get corresponding (line + n) filename.
	if (!filename)
		clear_exit_parsing(data, "Error\nTexture name conversion failed.");
//	dprintf(2, "path xpm : %s\n ", filename );
	texture->img.img = mlx_xpm_file_to_image(data->mlx.mlx, filename, &texture->width, &texture->length); //get an instance of the texture.
	if (!texture->img.img)
	{
		printf("Error\nProgram cannot load .%s.", filename);
		clear_exit_parsing(data, "");
		exit(EXIT_FAILURE);
	}
    texture->img.addr = mlx_get_data_addr(texture->img.img, &texture->img.bits_per_pixel, \
					&texture->img.line_lenght, &texture->img.endian);
}


