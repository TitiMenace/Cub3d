/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:24:53 by tschecro          #+#    #+#             */
/*   Updated: 2024/02/01 17:34:14 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"

void	*block_A_checker_open_path(char *line, t_data *data, t_texture *texture)
{
	char	*filename;
	int		x;
	int		y;

	filename = ft_get_textures_name(line + utils_skip_spaces(line)); //moove the offset of line too get corresponding (line + n) filename.
	if (!filename)
		clear_exit_parsing(data, "Error\nTexture name conversion failed.");
	texture->data = mlx_xpm_file_to_image(data->mlx.mlx, filename, &texture->width, &texture->length); //get an instance of the texture.
	if (!texture->data)
	{
		printf("Error\nProgram cannot load .%s.", filename);
		clear_exit_parsing(data, "");
		exit(EXIT_FAILURE);
	}
}


