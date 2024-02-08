/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:56:32 by greengo           #+#    #+#             */
/*   Updated: 2024/02/08 11:41:14 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "includes.h"
#include "cub3d.h"

void	free_tab(int **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_map_array(char **tab, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	init_parsing_resources(t_data *data)
{
	data->fd = 0;
	data->c_floor = 0;
	data->c_ceiling = 0;
	data->map_start = 0;
	data->map_height = 0;
	data->line_size = NULL;
	data->spawn = 0;
	data->spawn_char = 0;
	data->player_pos_x = 0;
	data->player_pos_y = 0;
	data->path = NULL;
	data->map = NULL;
	data->map_copy = NULL;
}
