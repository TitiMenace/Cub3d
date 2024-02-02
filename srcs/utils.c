/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:56:32 by greengo           #+#    #+#             */
/*   Updated: 2024/01/26 04:39:47 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "includes.h"
#include "cub3d.h"

int utils_skip_spaces(char *line) //return the number of space before a non-space character.
{
    int i;

    i = 0;
    
    while(line[i] == ' ')
        i++;
    return (i);
}

int utils_open_map(char *map_name, t_data *data)
{
    int fd;
    
    fd = open(map_name, O_RDONLY);
    if (fd != -1)
	{
        data->fd = fd;  
		return (1);	
	}
    else
    {
        printf("Error\nCannot open file %s:", map_name);
        clear_exit_parsing(data, "");
    }
	return (0);
}

uint32_t	utils_convert_rgb_to_int(t_data *data, char **values_array)
{
	int32_t	red;
	int32_t	green;
	int32_t	blue;

	red = ft_atoi(values_array[0]);
	if (red < 0 || red > 255)
	{
		free(values_array);
		clear_exit_parsing(data, "Error\nRed value are not on the range.");
	}
	green = ft_atoi(values_array[1]);
	if (green < 0 || green > 255)
	{
		free(values_array);
		clear_exit_parsing(data, "Error\nGreen value are not on the range.");
	}
	blue = ft_atoi(values_array[2]);
	if (blue < 0 || blue > 255)
	{
		free(values_array);
		clear_exit_parsing(data, "Error\nBlue value are not on the range.");
	}
	return (red << 16) | (green << 8) | blue;
}

uint8_t	utils_line_is_not_map(char *line)
{
	if (line[utils_skip_spaces(line)] == '1')
		return (0);
	else
		return (1);
}

char	*ft_get_textures_name(char *line)
{
	char	*name;
	int		i;

	i = 0;
	name = malloc(sizeof(char) * ft_strlen(line));
	if (!name)
		return (NULL);
	while(line[i] != '\n')
	{
		name[i] = line[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}	 

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