/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkpos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:33:42 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 16:50:25 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_checkspace(t_list *list, int a, int b)
{
	if (list->map[a][b - 1] == ' ')
		return (-1);
	if (list->map[a][b + 1] == ' ')
		return (-1);
	if (list->map[a + 1][b] == ' ')
		return (-1);
	if (list->map[a - 1][b] == ' ')
		return (-1);
	if (list->map[a - 1][b - 1] == ' ')
		return (-1);
	if (list->map[a + 1][b + 1] == ' ')
		return (-1);
	if (list->map[a + 1][b - 1] == ' ')
		return (-1);
	if (list->map[a - 1][b + 1] == ' ')
		return (-1);
	return (0);
}

void	ft_dataposition2(t_list *list, int a, int b)
{
	if (list->map[a][b] == 'N')
	{
		list->planex = 0.66;
		list->planey = 0;
		list->dirx = 0;
		list->diry = -1;
		list->position = 1;
	}
	if (list->map[a][b] == 'S')
	{
		list->planex = -0.66;
		list->planey = 0;
		list->dirx = 0;
		list->diry = 1;
		list->position = 1;
	}
	list->map[a][b] = '0';
	list->comptpos = 1;
}

void	ft_dataposition(t_list *list, int a, int b)
{
	list->posy = a + 0.5;
	list->posx = b + 0.5;
	if (list->map[a][b] == 'E')
	{
		list->planex = 0;
		list->planey = 0.66;
		list->dirx = 1;
		list->diry = 0;
		list->position = 1;
	}
	if (list->map[a][b] == 'W')
	{
		list->planex = 0;
		list->planey = -0.66;
		list->dirx = -1;
		list->diry = 0;
		list->position = 1;
	}
	ft_dataposition2(list, a, b);
}

int		ft_checkerrorpos(t_list *list, int a, int b)
{
	if ((list->comptpos == 0) && (list->map[a][b] == 'N' ||
		list->map[a][b] == 'S' || list->map[a][b] == 'E' ||
		list->map[a][b] == 'W'))
	{
		if (ft_checkspace(list, a, b) == -1)
			return (-1);
		ft_dataposition(list, a, b);
	}
	else
		return (-1);
	return (0);
}

int		ft_checkpos(t_list *list)
{
	int a;
	int b;

	a = 1;
	while (list->map && list->map[a])
	{
		b = 0;
		while (list->map[a][b] != '\0')
		{
			if (ft_isalpha(list->map[a][b]))
				if (ft_checkerrorpos(list, a, b) == -1)
					return (-1);
			b++;
		}
		a++;
	}
	if (list->position != 1)
		return (-1);
	return (1);
}
