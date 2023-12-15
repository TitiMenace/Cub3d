/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:09 by greengo           #+#    #+#             */
/*   Updated: 2023/12/15 16:37:38 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

bool ft_check_extension(char *map_name) {
    if (!map_name || !*map_name)
    {
        printf("Missing map.");
        return (1);
    }
    else if (*map_name + ft_strlen(map_name - 4) != "." ||
         *map_name + ft_strlen(map_name - 3) != "c" ||
         *map_name + ft_strlen(map_name - 2) != "u" ||
         *map_name + ft_strlen(map_name - 1) != "b")
    {
        printf("unrecognized map format.");
        return (1);
    }
    return (0);
}

bool ft_check_files_right(char *map_name)
{
    int fd;
    fd = open(map_name, O_RDONLY);
    if (fd != -1)
    {
        close(fd);
        return (0);
    }
    else
    {
        perror("Error while opening file:");
        return (1);
    }
}