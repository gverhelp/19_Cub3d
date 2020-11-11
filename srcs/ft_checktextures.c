/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktextures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:34:13 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:29:23 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_textno(t_list *list)
{
	int		a;

	a = 0;
	if (list->textno[a] == 'N' && list->textno[a + 1] == 'O')
		a += 2;
	while (list->textno[a] != '\0' && list->textno[a] == ' ')
		a++;
	if (!(list->imgno = mlx_xpm_file_to_image(list->mlx,
					&list->textno[a], &list->texwidth, &list->texheight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (0);
}

int	ft_textso(t_list *list)
{
	int		a;

	a = 0;
	if (list->textso[a] == 'S' && list->textso[a + 1] == 'O')
		a += 2;
	while (list->textso[a] != '\0' && list->textso[a] == ' ')
		a++;
	if (!(list->imgso = mlx_xpm_file_to_image(list->mlx,
					&list->textso[a], &list->texwidth, &list->texheight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_textwe(t_list *list)
{
	int		a;

	a = 0;
	if (list->textwe[a] == 'W' && list->textwe[a + 1] == 'E')
		a += 2;
	while (list->textwe[a] != '\0' && list->textwe[a] == ' ')
		a++;
	if (!(list->imgwe = mlx_xpm_file_to_image(list->mlx,
					&list->textwe[a], &list->texwidth, &list->texheight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_textea(t_list *list)
{
	int		a;

	a = 0;
	if (list->textea[a] == 'E' && list->textea[a + 1] == 'A')
		a += 2;
	while (list->textea[a] != '\0' && list->textea[a] == ' ')
		a++;
	if (!(list->imgea = mlx_xpm_file_to_image(list->mlx,
					&list->textea[a], &list->texwidth, &list->texheight)))
	{
		write(1, "Error\nPath texture\n", 19);
		return (-1);
	}
	return (1);
}

int	ft_checktextures(t_list *list)
{
	if (list->textno[2] != ' ' || ft_textno(list) == -1)
		return (-1);
	if (list->textso[2] != ' ' || ft_textso(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgno);
		return (-1);
	}
	if (list->textwe[2] != ' ' || ft_textwe(list) == -1)
	{
		mlx_destroy_image(list->mlx, list->imgno);
		mlx_destroy_image(list->mlx, list->imgso);
		return (-1);
	}
	if (ft_checktextures2(list) == -1)
		return (-1);
	return (1);
}
