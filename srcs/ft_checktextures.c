#include "../include/cub3d.h"

int	ft_textNO(t_list *list)
{
	int		a;

	a = 0;
	if (list->textNO[a] == 'N' && list->textNO[a + 1] == 'O')
		a += 2;
	while (list->textNO[a] != '\0' && list->textNO[a] == ' ')
		a++;
	if (!(list->imgNO = mlx_xpm_file_to_image(list->mlx,
		&list->textNO[a], &list->texWidth, &list->texHeight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (0);
}

int	ft_textSO(t_list *list)
{
	int		a;

	a = 0;
	if (list->textSO[a] == 'S' && list->textSO[a + 1] == 'O')
		a += 2;
	while (list->textSO[a] != '\0' && list->textSO[a] == ' ')
		a++;
	if (!(list->imgSO = mlx_xpm_file_to_image(list->mlx,
		&list->textSO[a], &list->texWidth, &list->texHeight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_textWE(t_list *list)
{
	int		a;

	a = 0;
	if (list->textWE[a] == 'W' && list->textWE[a + 1] == 'E')
		a += 2;
	while (list->textWE[a] != '\0' && list->textWE[a] == ' ')
		a++;
	if (!(list->imgWE = mlx_xpm_file_to_image(list->mlx,
		&list->textWE[a], &list->texWidth, &list->texHeight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_textEA(t_list *list)
{
	int		a;

	a = 0;
	if (list->textEA[a] == 'E' && list->textEA[a + 1] == 'A')
		a += 2;
	while (list->textEA[a] != '\0' && list->textEA[a] == ' ')
		a++;
	if (!(list->imgEA = mlx_xpm_file_to_image(list->mlx,
		&list->textEA[a], &list->texWidth, &list->texHeight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int     ft_checkTextures(t_list *list)
{
	if (list->textNO[2] != ' ' || ft_textNO(list) == -1)
		return (-1);
	if (list->textSO[2] != ' ' || ft_textSO(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgNO);
		return (-1);
	}
	if (list->textWE[2] != ' ' || ft_textWE(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgNO);
		mlx_destroy_image(list->mlx, list->imgSO);
		return (-1);
	}
	if (ft_checkTextures2(list) == -1)
		return (-1);
	return (1);
}