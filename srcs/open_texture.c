/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:24:53 by tschecro          #+#    #+#             */
/*   Updated: 2024/01/26 03:40:52 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"




int	**parse_sprites(char *pixel, t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		**tab;

	i = 0;
	k = 0;
	tab = malloc(sizeof(int *) * 512);
	if (!tab)
		return (NULL);
	while (i < 512)
	{
		j = 0;
		tab[i] = malloc(sizeof(int) * 512);
		if (!tab[i])
			return (free_tab(tab), NULL);
		while (j < 512)
		{
			tab[i][j] = rgb_convert((unsigned char)pixel[k + 2],
					(unsigned char)pixel[k + 1], (unsigned char)pixel[k]);
			k += 4;
			j++;
		}
		i++;
	}
	mlx_destroy_image(data->mlx.mlx, data->img.img);
	return (tab);
}





void	*block_A_checker_open_path(char *line, t_data *data)
{
	char	*filename;
	int		x;
	int		y;

	filename = line + utils_skip_spaces(line); //moove the offset of line too get corresponding (line + n) filename.
	data->img.img = mlx_xpm_file_to_image(data->mlx.mlx, filename, &x, &y); //get an instance of the texture.
	if (!data->img.img)
	{
		printf("Error\nProgram cannot load %s", filename);
		clear_exit_parsing(data, "");
		exit(EXIT_FAILURE);
	}
	if (x != 512 || y != 512)
	{
		printf("Error\nWrong sprite size\n");
		clear_exit_parsing(data, "");
		exit(EXIT_FAILURE);
	}
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, \
			&data->img.line_lenght, &data->img.endian);
	return (parse_sprites(data->img.addr, data));
}


