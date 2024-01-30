/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 00:23:44 by greengo           #+#    #+#             */
/*   Updated: 2024/01/30 09:36:21 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include "includes.h"

void    clear_exit_parsing(t_data *data, char *error_message)
{
	if(data->fd != -1)
		close(data->fd);
	if (data->no_texture)
		free(data->no_texture);
	if (data->so_texture)
		free(data->so_texture);
	if (data->ea_texture)
		free(data->ea_texture);
	if (data->we_texture)
		free(data->we_texture);
	if (*error_message)
		perror(error_message);
	exit(EXIT_FAILURE);
}