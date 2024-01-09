
#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

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

typedef struct s_data
{
	int				dir_y;
	int				dir_x;
	int				c_floor;
	int				c_ceiling;
	int				no_texture;
	int				so_texture;
	int				we_texture;
	int				ea_texture;
	t_mlx			mlx;
	t_img			img;
	float			player_pos_x;
	float			player_pos_y;
	char			*path;
	char			**map;
}				t_data;

#endif
