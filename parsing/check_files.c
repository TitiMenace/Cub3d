/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: greengo <greengo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:02:09 by greengo           #+#    #+#             */
/*   Updated: 2023/12/15 16:02:28 by greengo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

bool ft_check_extension(char *extension_name) {
    if (!extension_name || !*extension_name)
    {
        printf("Missing map.");
        return (1);
    }
    else if (*extension_name + ft_strlen(extension_name - 4) != "." ||
         *extension_name + ft_strlen(extension_name - 3) != "c" ||
         *extension_name + ft_strlen(extension_name - 2) != "u" ||
         *extension_name + ft_strlen(extension_name - 1) != "b")
    {
        printf("unrecognized map format.");
        return (1);
    }
    return (0);
}