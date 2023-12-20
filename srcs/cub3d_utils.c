
#include "includes.h"
#include "cub3d.h"
#include "struct.h"

void	ft_bzero(void *ptr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int			*pixel_addr;
	u_int8_t	test;
	float		alpha;
	int			old_color;

	if (data->mlx.w_h < 1920 || data->mlx.w_w < 1080)
		pixel_addr = (int *)(data->img.addr) + data->mlx.w_w * y + x;
	else
		pixel_addr = ((int *)(data->img.addr)
				+ ((y << 10) + (y << 9) + (y << 8) + (y << 7) + x));
	test = color >> 24;
	alpha = (float)test / (float)0xFF;
	color = (color << 8) >> 8;
	old_color = *pixel_addr;
	color = color_from_alpha((unsigned int)old_color \
			, (unsigned int)color, alpha);
	*pixel_addr = color;
}
