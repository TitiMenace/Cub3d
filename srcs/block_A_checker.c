/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_A_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:30:16 by greengo           #+#    #+#             */
/*   Updated: 2024/02/03 11:36:52 by sydauria         ###   ########.fr       */
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

uint32_t	block_a_checker_get_colors(char *line, t_data *data)
{
	uint32_t	offset;
	uint32_t	colors;
	char		**values;

	offset = utils_skip_spaces(line);
	values = ft_split(line + offset, ','); // check le retour de values qui peut etre null
	if (block_a_checker_array(values)) //check if array has well allocated, if isn't return 0, if allocation is good, check how many blocks has been allocated, if less or more than 3 free array and return 0.
	{
		colors = utils_convert_rgb_to_int(data, values);//convert the 3 values on one 32 bits int;
		free(values);
		// free le reste du tableau ?
		return (colors << 8);
	}	
	else
	{
		clear_exit_parsing(data, "Error\nError detected while colors conversion. Please check the format.");
		return (0);
	}
}
