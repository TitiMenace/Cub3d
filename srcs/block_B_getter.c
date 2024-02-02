/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_B_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 04:43:38 by greengo           #+#    #+#             */
/*   Updated: 2024/01/30 09:41:21 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    block_b_getter_array(t_data *data)
{
    char    *line;

    data->map_height = 0;
    line = get_next_line(data->fd);
    while (line)
    {
        free(line);
        line = get_next_line(data->fd);
        data->map_height++;
    }
    close(data->fd);
    data->map = malloc(sizeof(char *) * data->map_height + 1);
    if (!data->map)
        clear_exit_parsing(data, "Error\nMalloc map array failed.");
    data->line_size = malloc(sizeof(int) * data->map_height + 1);
    if (!data->line_size)
        clear_exit_parsing(data, "Error\nMalloc line size array failed.");
}

void    come_back_to_block_b(t_data *data, char *map_name)
{
    char    *line;
    int     height;
    
    height = data->map_height;
    check_file_acces_open_file(map_name, data);
    while (--height)
    {
        line = get_next_line(data->fd);
        free(line);
    }
}

void    duplicate_map(t_data *data)
{
    char    *line;
    int     i;

    i = 0;
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

bool    floodfill(char **map, int map_height, int *line_size, int x, int y, char spawn_char)
{
    if (x < 0 || x >= line_size[y] || y < 0 || y >= map_height || map[y][x] == '1')
        return (1);
    if (map[y][x] != '0' && map[y][x] != spawn_char)
        return (0);
    map[y][x] = '1';
    if (!floodfill(map, map_height, line_size, x + 1, y, spawn_char))
        return (0);
    if (!floodfill(map, map_height, line_size, x - 1, y, spawn_char))
        return (0);
    if (!floodfill(map, map_height, line_size, x, y + 1, spawn_char))
        return (0);
    if (!floodfill(map, map_height, line_size, x, y - 1, spawn_char)) 
        return (0);
    return (1);
}

static void    get_pos_direction(t_data *data, char pos)
{
    if (pos == 'E')
    {
        data->angle.vec_x = 1;
        data->angle.vec_y = 0;
    }
    if (pos == 'N')
    {
        data->angle.vec_x = -1;
        data->angle.vec_y = 0;
    }
    if (pos == 'W')
    {
        data->angle.vec_x = 0;
        data->angle.vec_y = -1;
    }
    if (pos == 'S')
    {
        data->angle.vec_x = 1;
        data->angle.vec_y = 0;
    }
}

void    print_map(char **map)
{
    int x = 0;
    while (map[x])
    {
        printf("%s", map[x]);
           x++; 
    }
}

void    get_start_pos(t_data *data)
{
    int     x; 
    int     y;

    x = 0;
    y = 0;
   // print_map(data->map);
    data->spawn = 0;
    while(y < data->map_height)
    {
        while(x < data->line_size[y])
        {
            if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'W' || data->map[y][x] == 'E')
            {
                data->spawn++;
                data->player_pos_x = x + 0.5;
                data->player_pos_y = y + 0.5;
                get_pos_direction(data, data->map[y][x]);
                data->spawn_char = data->map[y][x];
            }
            x++;    
        }
        x = 0;
        y++;
    }
    if (data->spawn != 1)
    {
        printf("Error\nOnly one spawn point accepted.");
        clear_exit_parsing(data, "");
    }
}