/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:37:05 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:55:27 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_write_sprites(t_list *list)
{
	int		a;
	int		b;

	a = list->drawstarty;
	b = 0;
	while (a < list->drawendy)
	{
		b = a * 256 - list->screenheight * 128 +
			list->spriteheight * 128;
		list->texy = ((b * 64) / list->spriteheight) / 256;
		if ((list->addrsprite[64 * list->texy + list->texx] & 0x00FFFFFF) != 0)
			list->addr[a * list->screenwidth + list->stripe] =
				list->addrsprite[64 * list->texy + list->texx];
		a++;
	}
}

void	ft_verline_sprites(t_list *list)
{
	list->stripe = list->drawstartx;
	while (list->stripe < list->drawendx)
	{
		list->texx = (int)((list->stripe - (-list->spritewidth / 2
			+ list->spritescreenx)) * 64 / list->spritewidth);
		if (list->transformy > 0 && list->stripe > 0 &&
			list->stripe < list->screenwidth &&
			list->transformy < list->zbuffer[list->stripe] && list->texx < 64)
			ft_write_sprites(list);
		list->stripe++;
	}
}
