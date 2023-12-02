
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

typedef struct s_data
{
	t_mlx	mlx;
}				t_data;

#endif
