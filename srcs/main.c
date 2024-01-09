
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

bool	pos_y_p(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'S')
		{
			data->player_pos_y = i + 0.5;
			return (true);
		}
		i++;
	}
	return (false);
}

bool	parsing(t_data *data)
{

	int	i;
	int fd;
	fd = open("test", O_RDONLY);
	data->map = malloc(88);
	if (!data->map)
		return (false);
	i = 0;
	while (i < 10)
	{
		data->map[i] = get_next_line(fd);
		if (pos_y_p(data->map[i], data))
			data->player_pos_x = i + 0.5;

		i++;
	}
	data->map[i] = 0;
	return (true);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[y])
		{
			if (data->map[x][y] == '1')
				draw_square(y * 10, x * 10, 0xFF0000, 10, data);
			else
				draw_square( y * 10, x * 10, 0x00FF00, 10, data);
			y++;
		}
		x++;
	}
	draw_square(data->player_pos_y * 10 - 2, data->player_pos_x * 10 - 2, 0x0000FF, 5, data);
	
}


int	rendering(t_data *data)
{
	set_floor_and_ceiling(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->img.img, 0, 0);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	(void)ac;
	
	ft_bzero(&data, sizeof(t_data));
	if (!init_mlx(&data))
		return (1);
	if (!parsing(&data))
		return (1);
	data.c_floor = rgb_to_int(128, 128, 128);
	data.c_ceiling = rgb_to_int(0, 0, 80);
	mlx_loop_hook(data.mlx.mlx, rendering, &data);
	init_hooks(&data);
	mlx_loop(data.mlx.mlx);
}
