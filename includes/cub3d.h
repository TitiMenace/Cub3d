/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/12/20 16:54:49 by titilamenace     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "struct.h"
# include "../lib/minilibx/mlx.h"

/* -------------------------------------------------------------------------- */
/*                         FILE = Cub3d/srcs/hooks.c                          */
/* -------------------------------------------------------------------------- */
int	destroy(t_data *data);
int	cross_button(t_data *data);
void	init_hooks(t_data *data);

/* -------------------------------------------------------------------------- */
/*                      FILE = Cub3d/srcs/cub3d_utils.c                       */
/* -------------------------------------------------------------------------- */
int		rgb_to_int(int r, int g, int b);
void	ft_bzero(void *ptr, size_t count);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/* -------------------------------------------------------------------------- */
/*                     FILE = Cub3d/srcs/set_background.c                     */
/* -------------------------------------------------------------------------- */
void	set_floor_and_ceiling(t_data *data);

/* -------------------------------------------------------------------------- */
/*                          FILE = Cub3d/srcs/main.c                          */
/* -------------------------------------------------------------------------- */
bool	init_mlx(t_data *data);
int	main(int ac, char **av);

char	*ft_fill_line(char *buffer, int fd, char **remain);
char	*clean_remain(char *remain);
char	*get_next_line(int fd);
char	*ft_strndup(char *str);
int		ft_strlen(char *str);
char	*ft_strjoin(char *remain, char *buffer);
	
int	check_buff(char *buffer, char c);
void	draw_square(int pos_x, int pos_y, int color, int size, t_data *data);

#endif
