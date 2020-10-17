#include "../include/cub3d.h"

int		ft_checkTextures2(t_list *list)
{
	if (list->textEA[2] != ' ' || ft_textEA(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgWE);
		mlx_destroy_image(list->mlx, list->imgSO);
		mlx_destroy_image(list->mlx, list->imgNO);
		return (-1);
	}
	list->addrNO = (int*)mlx_get_data_addr(list->imgNO, &list->bits_per_pixel,
        &list->line_length, &list->endian);
	list->addrSO = (int*)mlx_get_data_addr(list->imgSO, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	list->addrWE = (int*)mlx_get_data_addr(list->imgWE, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	list->addrEA = (int*)mlx_get_data_addr(list->imgEA, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	return (0);
}