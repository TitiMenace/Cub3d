/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmechety <rmechety@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by rmechety          #+#    #+#             */
/*   Updated: 2023/12/20 16:52:51 by titilamenace     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "includes.h"
# include "struct.h"
# include "../lib/minilibx/mlx.h"

/* -------------------------------------------------------------------------- */
/*                  FILE = Cub3d/lib/minilibx/mlx_set_font.c                  */
/* -------------------------------------------------------------------------- */
void	mlx_set_font(t_xvar *xvar, t_win_list *win, char *name);

/* -------------------------------------------------------------------------- */
/*                  FILE = Cub3d/lib/minilibx/test/new_win.c                  */
/* -------------------------------------------------------------------------- */
int gere_mouse(int x,int y,int button,void*toto);
int main();

/* -------------------------------------------------------------------------- */
/*                   FILE = Cub3d/lib/minilibx/test/main.c                    */
/* -------------------------------------------------------------------------- */
int	color_map_1(void *win,int w,int h);;
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);;
int	expose_win1(void *p);
int	expose_win2(void *p);
int	key_win1(int key,void *p);
int	key_win2(int key,void *p);
int	key_win3(int key,void *p);
int	mouse_win1(int button,int x,int y, void *p);
int	mouse_win2(int button,int x,int y, void *p);
int	mouse_win3(int x,int y, void *p);
int	main();
int	color_map_1(void *win,int w,int h);
int	color_map_2(unsigned char *data,int bpp,int sl,int w,int h,int endian, int type);

/* -------------------------------------------------------------------------- */
/*               FILE = Cub3d/lib/minilibx/mlx_int_do_nothing.c               */
/* -------------------------------------------------------------------------- */
int	mlx_int_do_nothing(void *param);

/* -------------------------------------------------------------------------- */
/*            FILE = Cub3d/lib/minilibx/mlx_int_anti_resize_win.c             */
/* -------------------------------------------------------------------------- */
int	mlx_int_anti_resize_win(t_xvar *xvar,Window win,int w,int h);

/* -------------------------------------------------------------------------- */
/*                   FILE = Cub3d/lib/minilibx/mlx_xpm.c.ok                   */
/* -------------------------------------------------------------------------- */
#define	RETURN	{ if (colors) free(colors); if (tab) free(tab); \;
char	*mlx_int_get_line(char *ptr,int *pos,int size);
char	*mlx_int_static_line(char **xpm_data,int *pos,int size);
int	mlx_int_get_col_name(char *str,int size);
int	mlx_int_get_text_rgb(char *name);
int	mlx_int_xpm_set_pixel(t_img *img, char *data, int opp, int col, int x);
void	*mlx_int_parse_xpm(t_xvar *xvar,void *info,int info_size,char *(*f)());
int	mlx_int_file_get_rid_comment(char *ptr, int size);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height);
void	*mlx_xpm_to_image(t_xvar *xvar,char **xpm_data,int *width,int *height);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_loop_hook.c                  */
/* -------------------------------------------------------------------------- */
int	mlx_loop_hook(t_xvar *xvar,int (*funct)(),void *param);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_mouse_hook.c                 */
/* -------------------------------------------------------------------------- */
int		mlx_mouse_hook(t_win_list *win,int (*funct)(),void *param);

/* -------------------------------------------------------------------------- */
/*              FILE = Cub3d/lib/minilibx/mlx_get_color_value.c               */
/* -------------------------------------------------------------------------- */
int             mlx_get_color_value(t_xvar *xvar,int color);
int		mlx_int_get_good_color(t_xvar *xvar,int color);

/* -------------------------------------------------------------------------- */
/*                    FILE = Cub3d/lib/minilibx/mlx_rgb.c                     */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                    FILE = Cub3d/lib/minilibx/mlx_init.c                    */
/* -------------------------------------------------------------------------- */
void	*mlx_init();
int		mlx_int_deal_shm(t_xvar *xvar);
int		mlx_int_rgb_conversion(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                  FILE = Cub3d/lib/minilibx/mlx_key_hook.c                  */
/* -------------------------------------------------------------------------- */
int		mlx_key_hook(t_win_list *win,int (*funct)(),void *param);

/* -------------------------------------------------------------------------- */
/*                FILE = Cub3d/lib/minilibx/mlx_flush_event.c                 */
/* -------------------------------------------------------------------------- */
int	mlx_flush_event(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*              FILE = Cub3d/lib/minilibx/mlx_destroy_display.c               */
/* -------------------------------------------------------------------------- */
int	mlx_destroy_display(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                   FILE = Cub3d/lib/minilibx/mlx_mouse.c                    */
/* -------------------------------------------------------------------------- */
int		mlx_mouse_move(t_xvar *xvar, t_win_list *win, int x, int y);
int		mlx_mouse_hide(t_xvar *xvar, t_win_list *win);
int		mlx_mouse_show(t_xvar *xvar, t_win_list *win);
int		mlx_mouse_get_pos(t_xvar *xvar, t_win_list *win, \;

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_string_put.c                 */
/* -------------------------------------------------------------------------- */
int		mlx_string_put(t_xvar *xvar,t_win_list *win,;

/* -------------------------------------------------------------------------- */
/*           FILE = Cub3d/lib/minilibx/mlx_int_wait_first_expose.c            */
/* -------------------------------------------------------------------------- */
int	mlx_int_wait_first_expose(t_xvar *xvar,Window win);

/* -------------------------------------------------------------------------- */
/*              FILE = Cub3d/lib/minilibx/mlx_int_param_event.c               */
/* -------------------------------------------------------------------------- */
int	mlx_int_param_undef();
int	mlx_int_param_KeyPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_KeyRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_ButtonPress(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_ButtonRelease(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_MotionNotify(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_Expose(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	mlx_int_param_generic(t_xvar *xvar, XEvent *ev, t_win_list *win);
int	(*(mlx_int_param_event[]))() =;

/* -------------------------------------------------------------------------- */
/*             FILE = Cub3d/lib/minilibx/mlx_int_str_to_wordtab.c             */
/* -------------------------------------------------------------------------- */
int	mlx_int_str_str(char *str,char *find,int len);
int	mlx_int_str_str_cote(char *str,char *find,int len);
char	**mlx_int_str_to_wordtab(char *str);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_pixel_put.c                  */
/* -------------------------------------------------------------------------- */
int		mlx_pixel_put(t_xvar *xvar,t_win_list *win,;

/* -------------------------------------------------------------------------- */
/*               FILE = Cub3d/lib/minilibx/mlx_get_data_addr.c                */
/* -------------------------------------------------------------------------- */
char	*mlx_get_data_addr(t_img *img,int *bits_per_pixel,;

/* -------------------------------------------------------------------------- */
/*               FILE = Cub3d/lib/minilibx/mlx_destroy_window.c               */
/* -------------------------------------------------------------------------- */
int	mlx_destroy_window(t_xvar *xvar,t_win_list *win);

/* -------------------------------------------------------------------------- */
/*           FILE = Cub3d/lib/minilibx/mlx_int_set_win_event_mask.c           */
/* -------------------------------------------------------------------------- */
int	mlx_int_set_win_event_mask(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                FILE = Cub3d/lib/minilibx/mlx_clear_window.c                */
/* -------------------------------------------------------------------------- */
int		mlx_clear_window(t_xvar *xvar,t_win_list *win);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_new_image.c                  */
/* -------------------------------------------------------------------------- */
int	shm_att_pb(Display *d,XErrorEvent *ev);
void	*mlx_int_new_xshm_image(t_xvar *xvar,int width,int height,int format);
void	*mlx_int_new_image(t_xvar *xvar,int width, int height,int format);
void	*mlx_new_image(t_xvar *xvar,int width, int height);
void	*mlx_new_image2(t_xvar *xvar,int width, int height);

/* -------------------------------------------------------------------------- */
/*                FILE = Cub3d/lib/minilibx/mlx_expose_hook.c                 */
/* -------------------------------------------------------------------------- */
int		mlx_expose_hook(t_win_list *win,int (*funct)(),void *param);

/* -------------------------------------------------------------------------- */
/*               FILE = Cub3d/lib/minilibx/mlx_destroy_image.c                */
/* -------------------------------------------------------------------------- */
int	mlx_destroy_image(t_xvar *xvar, t_img *img);

/* -------------------------------------------------------------------------- */
/*                    FILE = Cub3d/lib/minilibx/mlx_loop.c                    */
/* -------------------------------------------------------------------------- */
extern int	(*(mlx_int_param_event[]))();;
int			mlx_loop_end(t_xvar *xvar);
int			mlx_loop(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_ext_randr.c                  */
/* -------------------------------------------------------------------------- */
int			mlx_ext_fullscreen(t_xvar *xvar, t_win_list *win, int fullscreen);

/* -------------------------------------------------------------------------- */
/*            FILE = Cub3d/lib/minilibx/mlx_put_image_to_window.c             */
/* -------------------------------------------------------------------------- */
int	mlx_put_image_to_window(t_xvar *xvar,t_win_list *win,t_img *img,;

/* -------------------------------------------------------------------------- */
/*               FILE = Cub3d/lib/minilibx/mlx_int_get_visual.c               */
/* -------------------------------------------------------------------------- */
int		mlx_int_get_visual(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                    FILE = Cub3d/lib/minilibx/mlx_hook.c                    */
/* -------------------------------------------------------------------------- */
int	mlx_hook(t_win_list *win, int x_event, int x_mask, ;
int	mlx_do_key_autorepeatoff(t_xvar *xvar);
int	mlx_do_key_autorepeaton(t_xvar *xvar);
int	mlx_do_sync(t_xvar *xvar);

/* -------------------------------------------------------------------------- */
/*                    FILE = Cub3d/lib/minilibx/mlx_xpm.c                     */
/* -------------------------------------------------------------------------- */
#define	RETURN	{ if (colors) free(colors); if (tab) free(tab); \;
char	*mlx_int_get_line(char *ptr,int *pos,int size);
unsigned int	strlcpy_is_not_posix(char *dest, char *src, unsigned int size);
char	*mlx_int_static_line(char **xpm_data,int *pos,int size);
int	mlx_int_get_col_name(char *str,int size);
int	mlx_int_get_text_rgb(char *name, char *end);
int	mlx_int_xpm_set_pixel(t_img *img, char *data, int opp, int col, int x);
void	*mlx_int_parse_xpm(t_xvar *xvar,void *info,int info_size,char *(*f)());
int	mlx_int_file_get_rid_comment(char *ptr, int size);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *file,int *width,int *height);
void	*mlx_xpm_to_image(t_xvar *xvar,char **xpm_data,int *width,int *height);

/* -------------------------------------------------------------------------- */
/*                 FILE = Cub3d/lib/minilibx/mlx_new_window.c                 */
/* -------------------------------------------------------------------------- */
void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title);

/* -------------------------------------------------------------------------- */
/*                  FILE = Cub3d/lib/minilibx/mlx_lib_xpm.c                   */
/* -------------------------------------------------------------------------- */
void		*mlx_int_xpm_f_image(t_xvar *xvar,int *width,int *height,;
int	mlx_int_egal_img(XImage *img1,XImage *img2);
void	*mlx_xpm_file_to_image(t_xvar *xvar,char *filename,;
void	*mlx_xpm_to_image(t_xvar *xvar,char **data,int *width,int *height);

/* -------------------------------------------------------------------------- */
/*                FILE = Cub3d/lib/minilibx/mlx_screen_size.c                 */
/* -------------------------------------------------------------------------- */
int		mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

/* -------------------------------------------------------------------------- */
/*                         FILE = Cub3d/srcs/hooks.c                          */
/* -------------------------------------------------------------------------- */
int	destroy(t_data *data);
int	cross_button(t_data *data);
void	init_hooks(t_data *data);

/* -------------------------------------------------------------------------- */
/*                      FILE = Cub3d/srcs/cub3d_utils.c                       */
/* -------------------------------------------------------------------------- */
int	argb_to_int(int a, int r, int g, int b);
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


#endif
