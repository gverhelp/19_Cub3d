/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:49 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 16:54:58 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_walltexture(t_list *list)
{
	if (list->side == 0)
		list->wallx = list->posy + list->perpwalldist * list->raydiry;
	else
		list->wallx = list->posx + list->perpwalldist * list->raydirx;
	list->wallx -= floor((list->wallx));
	list->texx = (int)(list->wallx * (double)list->texwidth);
	if (list->side == 0 && list->raydirx > 0)
		list->texx = list->texwidth - list->texx - 1;
	if (list->side == 1 && list->raydiry < 0)
		list->texx = list->texwidth - list->texx - 1;
	list->step = 1.0 * list->texwidth / list->lineheight;
	list->texpos = (list->drawstart - list->screenheight / 2 +
			list->lineheight / 2) * list->step;
	return (0);
}

void	ft_verline2(t_list *list, int a, int b)
{
	list->texy = (int)list->texpos & (list->texheight - 1);
	list->texpos += list->step;
	if (list->side == 1 && list->raydiry < 0)
		list->color = list->addrno[list->texheight * list->texy + list->texx];
	if (list->side == 1 && list->raydiry > 0)
		list->color = list->addrso[list->texheight * list->texy + list->texx];
	if (list->side == 0 && list->raydirx < 0)
		list->color = list->addrwe[list->texheight * list->texy + list->texx];
	if (list->side == 0 && list->raydirx > 0)
		list->color = list->addrea[list->texheight * list->texy + list->texx];
	list->addr[b * list->screenwidth + a] = list->color;
}

void	ft_verline(t_list *list, int a)
{
	int	b;

	b = 0;
	while (b < list->drawstart)
	{
		list->addr[b * list->screenwidth + a] = list->color_sky;
		b++;
	}
	while (b <= list->drawend)
	{
		ft_verline2(list, a, b);
		b++;
	}
	while (b < list->screenheight)
	{
		list->addr[b * list->screenwidth + a] = list->color_floor;
		b++;
	}
}
