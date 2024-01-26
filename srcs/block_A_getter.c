/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_A_getter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 22:15:17 by greengo           #+#    #+#             */
/*   Updated: 2024/01/26 03:22:06 by tschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "includes.h"
#include "cub3d.h"

static bool    block_A_getter_need_that_data(char *line) //return true if the line need to be stock in struct
{

    if (line[0] == 'N' && line[1] == 'O')
        return (1);
    else if (line[0] == 'S' && line[1] == 'O')
        return (1);
    else if (line[0] == 'E' && line[1] == 'A')
        return (1);
    else if (line[0] == 'W' && line[1] == 'E')
        return (1);
    else if (line[0] == 'F')
        return (1);
    else if (line[0] == 'C')
        return (1);
    else 
        return (0);
}

//to review
static void    block_A_getter_set_data(char *line, t_data *data) //store textures and colors in struct
{
    if (line[0] == 'N' && line[1] == 'O')
        data->no_texture = block_A_checker_open_path(line, data);
    else if (line[0] == 'S' && line[1] == 'O')
        data->so_texture = block_A_checker_open_path(line, data);
    else if (line[0] == 'E' && line[1] == 'A')
        data->ea_texture = block_A_checker_open_path(line, data);
    else if (line[0] == 'W' && line[1] == 'E')
        data->we_texture = block_A_checker_open_path(line, data);
    else if (line[0] == 'F')
        data->c_floor = block_A_checker_get_colors(line, data); 
    else if (line[0] == 'C')
        data->c_ceiling = block_A_checker_get_colors(line, data); 
}

static bool block_A_getter_is_full(t_data *data) //return true if all path are filled
{
    if (data->no_texture && data->so_texture && data->ea_texture && data->we_texture && data->c_ceiling && data->c_floor)
        return (1);
    else 
        return (0);
}

static bool    block_A_getter_invalid_line(char *line) //return true if map pattern is incorrect
{
    int i; 
    
    i = utils_skip_spaces(line);
    if (line[i] != '\n')
        return (1);
    else
        return (0);
}


void        block_A_getter_textures_colors(t_data *data) //filling the struct with textures and colors
{
    char *line;
    
    line = get_next_line(data->fd);
    data->map_start++;
    while (line)
    {
        if (block_A_getter_need_that_data(line))
        {
            block_A_getter_set_data(line, data);
            if (block_A_getter_is_full(data))
                return ;
        }
        else if (block_A_getter_invalid_line(line))
        {
            printf("Error\nMap format is not standard.");
            clear_exit_parsing(data, "");
        }
        else
            free(line);
        line = get_next_line(data->fd);
        data->map_start++;
    }
}
