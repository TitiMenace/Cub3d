
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

bool	init_mlx(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		return (false);
	if (WIN_WIDTH <= 0 || WIN_HEIGHT <= 0)
		return (false);
	else
	{
		data->mlx.w_w = WIN_WIDTH;
		data->mlx.w_h = WIN_HEIGHT;
	}
	data->mlx.win = mlx_new_window(data->mlx.mlx, data->mlx.w_w, \
			data->mlx.w_h, "cub3d");
	if (!data->mlx.win)
		return (false);
	data->img.img = mlx_new_image(data->mlx.mlx, data->mlx.w_w, data->mlx.w_h);
	if (!data->img.img)
		return (false);
	data->img.addr = mlx_get_data_addr(data->img.img, \
			&data->img.bits_per_pixel, &data->img.line_lenght, \
			&data->img.endian);
	return (true);
}

/*void	rendering(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
}
*/

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	(void)ac;
	ft_bzero(&data, sizeof(t_data));
	if (!init_mlx(&data))
		return (1);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
}
