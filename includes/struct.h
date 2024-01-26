
#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>


typedef struct s_vec2
{
	float	x;
	float	y;
}				t_vec2;


typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		w_w;
	int		w_h;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct s_angle
{
	float	vec_x;
	float	vec_y;
	float	rad;
}			t_angle;

typedef struct s_line
{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
}			t_line;


typedef struct s_r_cast
{
	double	cameraX;
	double	ray_dirX;
	double	ray_dirY;
	int		map_x;
	int		map_y;
	double	sideDistX;
	double	sideDistY;
	double	delta_DistX;
	double	delta_DistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
}			t_r_cast;



typedef struct s_data
{
	double			plane_X;
	double			plane_Y;
	int				c_floor;
	int				c_ceiling;
	int				**no_texture;
	int				**so_texture;
	int				**we_texture;
	int				**ea_texture;
	t_mlx			mlx;
	t_img			img;
	t_angle			angle;
	float			player_pos_x;
	float			player_pos_y;
	char			*path;
	char			**map;
	float			speed;
	float			rs;
	int				side;
}				t_data;

#endif
