/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2185/10/26 14:41:58 by greengo           #+#    #+#             */
/*   Updated: 2024/01/20 23:06:03 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "struct.h"
// #include "includes.h"

// int32_t    check_file_content_line(char *line) // to remove
// {
//     int     i;

//     i = 0;
//     while(line[i] != '\n')
//     {
//         if (line[i] != '0' || line[i] != '1' || line[i] != 'N' || line[i] != 'S' || line[i] != 'E' || line[i] != 'W')
//         {
//             printf("Error\nInvalid character found on map.");
//             return (-1);
//         }
//         i++;        
//     }
//     return (i);
// }

// bool    check_file_content(char *map_name, t_data *data) //remove? 
// {
//     char    *line_to_check;

//     check_file_acces_open_file(map_name, data);
//     line_to_check = get_next_line(data->fd);
//     data->map_start++;
//     while (line_to_check)
//     {
//         if (check_file_content_line(line_to_check) == -1) 
//         {
//             free(line_to_check);
//             close(data->fd);
//             return (1);
//         }
//         free(line_to_check);
//         line_to_check = get_next_line(data->fd);
//         data->map_start++;
//     }
//     close(data->fd);
//     return (0);
// }

