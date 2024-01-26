/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_B_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:43:38 by greengo           #+#    #+#             */
/*   Updated: 2024/01/26 05:28:20 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    block_b_getter_array(t_data *data)
{
    char    *line;

    line = get_next_line(data->fd);
    while (line)
    {
        free(line);
        line = get_next_line(data->fd);
        data->map_height++;
    }
    close(data->fd);
    data->map = malloc(sizeof(char *) * data->map_height);
    if (!data->map)
        clear_exit_parsing(data, "Error\nMalloc map array failed.");
    data->line_size = malloc(sizeof(int) * data->map_height);
    if (data->line_size)
        clear_exit_parsing(data, "Error\nMalloc line size array failed.");
}

void    come_back_to_block_b(t_data *data, char *map_name)
{
    char    *line;
    
    check_file_acces_open_file(map_name, data);
    while (data->map_height)
    {
        line = get_next_line(data->fd);
        free(line);
    }
}

void    duplicate_map(t_data *data)
{
    char    *line;
    int     i;

    line = get_next_line(data->fd);
    data->map[i] = line;
    data->line_size[i] = ft_strlen(line);
    i++;
    while (line)
    {
        line = get_next_line(data->fd);
        data->map[i] = line;
        data->line_size[i] = ft_strlen(line);
        i++;
    }
}

bool    floodfill(t_data data, int x, int y, char old_char, char new_char)
{
    if (x < 0 || x > data.line_size[y] || y < 0 || y > data.map_height || data.map[y][x] == new_char || data.map[y][x] != '1')
        return;
    if (data.map[y][x] != '0' || data.map[y][x] != old_char)
        return (0);
    data.map[y][x] = new_char;
    if (!floodfill(data, x + 1, y, old_char, new_char))
        return (0);
    if (!floodfill(data, x - 1, y, old_char, new_char))
        return (0);
    if (!floodfill(data, x, y + 1, old_char, new_char))
        return (0);
    if (!floodfill(data, x, y - 1, old_char, new_char))
        return (0);
    return (1);
}

bool    get_start_pos(t_data *data)
{
    int     x; 
    int     y;

    x = 0;
    y = 0;
    while(data->map[y][x])
    {
        while(data->map[y][x])
        {
            if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E' ||)
                
        }
    }
}