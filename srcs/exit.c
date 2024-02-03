/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:23:44 by greengo           #+#    #+#             */
/*   Updated: 2024/02/03 12:35:45 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include "includes.h"

void	clear_exit_parsing(t_data *data, char *error_message)
{
	if (data->fd != -1)
		close(data->fd);
	if (data->no_texture.img.addr)
		free(data->no_texture.img.addr);
	if (data->so_texture.img.addr)
		free(data->so_texture.img.addr);
	if (data->ea_texture.img.addr)
		free(data->ea_texture.img.addr);
	if (data->we_texture.img.addr)
		free(data->we_texture.img.addr);
	if (*error_message)
		perror(error_message);
	if (data->map)
		free_tab(data->map);
	if (data->map_copy)
		free_tab(data->map_copy);
	if (data->line_size)
		free(data->line_size);
	exit(EXIT_FAILURE);
}
