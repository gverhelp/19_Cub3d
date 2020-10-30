#include "../include/cub3d.h"

int		ft_textSprite(t_list *list)
{
	int		a;

	a = 0;
	if (list->textSprite[a] == 'S')
		a += 2;
	while (list->textSprite[a] != '\0' && list->textSprite[a] == ' ')
		a++;
	if (!(list->imgSprite = mlx_xpm_file_to_image(list->mlx,
		&list->textSprite[a], &list->texWidth, &list->texHeight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

void     ft_checkTextures3(t_list *list)
{
	list->addrNO = (int*)mlx_get_data_addr(list->imgNO, &list->bits_per_pixel,
        &list->line_length, &list->endian);
	list->addrSO = (int*)mlx_get_data_addr(list->imgSO, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	list->addrWE = (int*)mlx_get_data_addr(list->imgWE, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	list->addrEA = (int*)mlx_get_data_addr(list->imgEA, &list->bits_per_pixel,
		&list->line_length, &list->endian);
	list->addrSprite = (int*)mlx_get_data_addr(list->imgSprite, &list->bits_per_pixel,
		&list->line_length, &list->endian);
}

int		ft_checkTextures2(t_list *list)
{
	if (list->textEA[2] != ' ' || ft_textEA(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgWE);
		mlx_destroy_image(list->mlx, list->imgSO);
		mlx_destroy_image(list->mlx, list->imgNO);
		return (-1);
	}
	if (list->textSprite[1] != ' ' || ft_textSprite(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgWE);
		mlx_destroy_image(list->mlx, list->imgSO);
		mlx_destroy_image(list->mlx, list->imgNO);
		mlx_destroy_image(list->mlx, list->imgEA);
		return (-1);
	}
	ft_checkTextures3(list);
	return (0);
}