/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sydauria <sydauria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2024/02/02 13:50:13 by sydauria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "struct.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/42_libft/libft.h"

/* -------------------------------------------------------------------------- */
/*                                  PARSING                                   */
/* -------------------------------------------------------------------------- */
void        check_file_acces_open_file(char *map_name, t_data *data);
void        block_A_getter_textures_colors(t_data *data);
void        clear_exit_parsing(t_data *data, char *error_message);
void	    block_A_checker_open_path(char *line, t_data *data, t_texture *texture);
uint32_t	block_A_checker_get_colors(char *line, t_data *data);
uint8_t	    utils_line_is_not_map(char *line);
int         utils_skip_spaces(char *line);
int         utils_open_map(char *map_name, t_data *data);
uint32_t	utils_convert_rgb_to_int(t_data *data, char **values_array);
char    	*ft_get_textures_name(char *line);
bool        floodfill(char **map, int map_height, int *line_size, int x, int y, char spawn_char);
void        duplicate_map(t_data *data);
void        come_back_to_block_b(t_data *data, char *map_name);
void        block_b_getter_array(t_data *data);
void        get_start_pos(t_data *data);





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

	
int	check_buff(char *buffer, char c);
void	draw_square(int pos_x, int pos_y, int color, int size, t_data *data);
bool	check_collision(t_data *data, int x, int y);
void	casting_ray(t_data *data, t_vec2 *intersec);
void	draw_height_line(int x, t_line	*line, t_data *data, t_r_cast *values);
void	free_tab(int **tab);

#endif
