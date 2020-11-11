/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktextures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:34:22 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:31:09 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_textsprite(t_list *list)
{
	int		a;

	a = 0;
	if (list->textsprite[a] == 'S')
		a += 2;
	while (list->textsprite[a] != '\0' && list->textsprite[a] == ' ')
		a++;
	if (!(list->imgsprite = mlx_xpm_file_to_image(list->mlx,
		&list->textsprite[a], &list->texwidth, &list->texheight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

void	ft_checktextures3(t_list *list)
{
	list->addrno = (int*)mlx_get_data_addr(list->imgno, &list->bits_per_pixel,
			&list->line_length, &list->endian);
	list->addrso = (int*)mlx_get_data_addr(list->imgso, &list->bits_per_pixel,
			&list->line_length, &list->endian);
	list->addrwe = (int*)mlx_get_data_addr(list->imgwe, &list->bits_per_pixel,
			&list->line_length, &list->endian);
	list->addrea = (int*)mlx_get_data_addr(list->imgea, &list->bits_per_pixel,
			&list->line_length, &list->endian);
	list->addrsprite = (int*)mlx_get_data_addr(list->imgsprite,
		&list->bits_per_pixel, &list->line_length, &list->endian);
}

int	ft_checktextures2(t_list *list)
{
	if (list->textea[2] != ' ' || ft_textea(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgwe);
		mlx_destroy_image(list->mlx, list->imgso);
		mlx_destroy_image(list->mlx, list->imgno);
		return (-1);
	}
	if (list->textsprite[1] != ' ' || ft_textsprite(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgwe);
		mlx_destroy_image(list->mlx, list->imgso);
		mlx_destroy_image(list->mlx, list->imgno);
		mlx_destroy_image(list->mlx, list->imgea);
		return (-1);
	}
	ft_checktextures3(list);
	return (0);
}
