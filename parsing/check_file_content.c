/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2185/10/26 14:41:58 by greengo           #+#    #+#             */
/*   Updated: 2023/12/15 17:24:16 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int32_t    check_line(char *line)
{
    int     i;

    i = 0;
    while(line[i] != '\n')
    {
        if (line[i] != '0' || line[i] != '1' || line[i] != 'N' || line[i] != 'S' || line[i] != 'E' || line[i] != 'W')
        {
            printf("Invalid character found on map.");
            return (-1);
        }        
    }
    return (i);
}

bool    check_file_characters(char *map_name) 
{
    int     fd;
    char    *line_to_check;

    fd = open(map_name);
    line_to_check = get_next_line(fd);
    while (line_to_check)
    {
        if (check_line(line_to_check) == -1) 
        {
            free(line_to_check);
            close(fd);
            return (1)
        }
        free(line_to_check);
        line_to_check = get_next_line(fd);
    }
    close(fd);
}

// bool    check_line_size(char *map_name)
// {
//     int fd;
//     int line_size;
//     char    *line_to_check;

//     fd = open(map_name);
    
    
//     line_size = check_line(get_next_line(fd));
//     while 
    
    
// }