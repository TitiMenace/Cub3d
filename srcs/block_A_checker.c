/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_A_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:30:16 by greengo           #+#    #+#             */
/*   Updated: 2024/02/08 16:55:29 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"

static bool	block_a_checker_array(char **values_array)
{
	uint8_t	nb_colors;

	nb_colors = 0;
	if (values_array)
	{
		while (values_array[nb_colors])
			nb_colors++;
		if (nb_colors == 3)
			return (1);
		else
		{
			free(values_array);
			return (0);
		}
	}
	else
		return (0);
}

bool	how_much_colors(char **values)
{
	int	i;

	i = 1;
	while (values[i])
		i++;
	if (i != 3)
		return (0);
	return (1);
}

uint32_t	block_a_checker_get_colors(char *line, t_data *data)
{
	uint32_t	offset;
	int32_t		colors;
	char		**values;

	offset = utils_skip_spaces(line + 1);
	values = ft_split(line + offset, ',');
	if (!values)
	{
		free(line);
		clear_exit_parsing(data, "Error\nFt_split failed\n");
	}
	if (!how_much_colors(values))
	{
		free_array(values);
		return (0);
	}
	if (block_a_checker_array(values))
	{
		colors = utils_convert_rgb_to_int(values);
		if (colors == -1)
		{
			free(line);
			clear_exit_parsing(data, "");
		}
		free_array(values);
		return (colors);
	}	
	else
	{
		free_array(values);
		clear_exit_parsing(data, "Error\nError detected while \
		colors conversion. Please check the format.\n");
		return (0);
	}
}
