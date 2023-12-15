
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
	t_mlx			mlx;
	t_img			img;
}				t_data;

#endif
