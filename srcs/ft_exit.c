/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:34:34 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:32:13 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_free_win(t_list *list)
{
	if (list->img)
		mlx_destroy_image(list->mlx, list->img);
	if (list->mlx && list->mlx_win)
		mlx_destroy_window(list->mlx, list->mlx_win);
	if (list->mlx)
	{
		free(list->mlx);
		list->mlx = NULL;
	}
}

void	ft_free_map(t_list *list)
{
	int	a;

	a = 0;
	if (list->map)
	{
		while (list->map && *list->map && list->map[a])
		{
			free(list->map[a]);
			list->map[a] = NULL;
			a++;
		}
		free(list->map);
		list->map = NULL;
	}
}

void	ft_free_data2(t_list *list)
{
	if (list->textea)
	{
		free(list->textea);
		list->textea = NULL;
	}
	if (list->textf)
	{
		free(list->textf);
		list->textf = NULL;
	}
	if (list->textc)
	{
		free(list->textc);
		list->textc = NULL;
	}
	if (list->textsprite)
	{
		free(list->textsprite);
		list->textsprite = NULL;
	}
}

void	ft_free_data(t_list *list)
{
	if (list->size)
	{
		free(list->size);
		list->size = NULL;
	}
	if (list->textno)
	{
		free(list->textno);
		list->textno = NULL;
	}
	if (list->textso)
	{
		free(list->textso);
		list->textso = NULL;
	}
	if (list->textwe)
	{
		free(list->textwe);
		list->textwe = NULL;
	}
	ft_free_data2(list);
}

int	ft_exit(t_list *list)
{
	ft_free_map(list);
	ft_free_data(list);
	ft_free_win(list);
	exit(0);
	return (-1);
}
