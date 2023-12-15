
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
