/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:58 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:54:06 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_calculate_draw_start_end(t_list *list)
{
	list->spriteheight = (int)fabs((double)list->screenheight /
		list->transformy);
	list->drawstarty = -list->spriteheight / 2 + list->screenheight / 2;
	if (list->drawstarty < 0)
		list->drawstarty = 0;
	list->drawendy = list->spriteheight / 2 + list->screenheight / 2;
	if (list->drawendy >= list->screenheight)
		list->drawendy = list->screenheight - 1;
	list->spritewidth = (int)fabs((double)list->screenheight
			/ list->transformy);
	list->drawstartx = -list->spritewidth / 2 + list->spritescreenx;
	if (list->drawstartx < 0)
		list->drawstartx = 0;
	list->drawendx = list->spritewidth / 2 + list->spritescreenx;
	if (list->drawendx >= list->screenwidth)
		list->drawendx = list->screenwidth - 1;
}

void	ft_calculate_transform(t_list *list, int a)
{
	list->sprtx = list->spritesx[a] - list->posx;
	list->sprty = list->spritesy[a] - list->posy;
	list->invdet = 1.0 / (list->planex * list->diry
		- list->dirx * list->planey);
	list->transformx = list->invdet * (list->diry *
		list->sprtx - list->dirx * list->sprty);
	list->transformy = list->invdet * (-list->planey *
		list->sprtx + list->planex * list->sprty);
	list->spritescreenx = (int)((list->screenwidth / 2) *
		(1 + list->transformx / list->transformy));
}

void	ft_switch_sprites(t_list *list, int a, int b)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = list->spritesx[a];
	tmp_y = list->spritesy[a];
	list->spritesx[a] = list->spritesx[b];
	list->spritesy[a] = list->spritesy[b];
	list->spritesx[b] = tmp_x;
	list->spritesy[b] = tmp_y;
}

void	ft_sort_sprite(t_list *list)
{
	int	a;
	int	b;

	a = 0;
	while (a < list->nbsprites - 1)
	{
		list->spritedistance = ((list->posx - list->spritesx[a]) *
			(list->posx - list->spritesx[a]) +
			(list->posy - list->spritesy[a]) *
			(list->posy - list->spritesy[a]));
		b = a + 1;
		while (b < list->nbsprites)
		{
			if (((list->posx - list->spritesx[b]) *
				(list->posx - list->spritesx[b]) +
				(list->posy - list->spritesy[b]) *
				(list->posy - list->spritesy[b])) > list->spritedistance)
				ft_switch_sprites(list, a, b);
			b++;
		}
		a++;
	}
}

void	ft_raycasting_sprites(t_list *list)
{
	int	a;

	a = 0;
	ft_sort_sprite(list);
	while (a < list->nbsprites)
	{
		ft_calculate_transform(list, a);
		ft_calculate_draw_start_end(list);
		ft_verline_sprites(list);
		a++;
	}
}
