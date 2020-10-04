/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 12:35:36 by gverhelp          #+#    #+#             */
/*   Updated: 2020/03/12 12:57:38 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_keyboard4(int keycode, t_list *list)
{
	if (keycode == 123) //fleche de gauche, tourner la camera vers la gauche
	{
		list->oldDirX = list->dirX;
		list->dirX = list->dirX * cos(-(list->rotspeed)) - list->dirY *
			sin(-(list->rotspeed));
		list->dirY = list->oldDirX * sin(-(list->rotspeed)) + list->dirY *
			cos(-(list->rotspeed));
		list->oldPlaneX = list->planeX;
		list->planeX = list->planeX * cos(-(list->rotspeed)) - list->planeY *
			sin(-(list->rotspeed));
		list->planeY = list->oldPlaneX * sin(-(list->rotspeed)) + list->planeY *
			cos(-(list->rotspeed));
	}
}

void	ft_keyboard3(int keycode, t_list *list)
{
	if (keycode == 2) //straff vers la droite avec D
	{
		if (list->map[(int)(list->posY + list->dirX * 0.5)][(int)list->posX] != '1')
			list->posY += list->dirX * list->movespeed; //0.4
		if (list->map[(int)list->posY][(int)(list->posX - list->dirY * 0.5)] != '1')
			list->posX -= list->dirY * list->movespeed; //0.4
	}
	if (keycode == 0) //straff vers la gauche avec Q
	{
		if (list->map[(int)(list->posY - list->dirX * 0.5)][(int)list->posX] != '1')
			list->posY -= list->dirX * list->movespeed; //0.4
		if (list->map[(int)list->posY][(int)(list->posX + list->dirY * 0.5)] != '1')
			list->posX += list->dirY * list->movespeed; //0.4
	}
	ft_keyboard4(keycode, list);
}

void	ft_keyboard2(int keycode, t_list *list)
{
	if (keycode == 13 || keycode == 126) //avancer avec fleche du haut (126) ou Z (13)
	{
		if (list->map[(int)list->posY][(int)(list->posX + list->dirX *
			list->movespeed)] != '1')
			list->posX += list->dirX * list->movespeed;
		if (list->map[(int)(list->posY + list->dirY * list->movespeed)]
			[(int)list->posX] != '1')
			list->posY += list->dirY * list->movespeed;
	}
	if (keycode == 1 || keycode == 125) //reculer avec fleche du bas (125) ou S (1)
	{
		if (list->map[(int)list->posY][(int)(list->posX - list->dirX *
			list->movespeed)] != '1')
			list->posX -= list->dirX * list->movespeed;
		if (list->map[(int)(list->posY - list->dirY * list->movespeed)]
			[(int)list->posX] != '1')
			list->posY -= list->dirY * list->movespeed;
	}
	ft_keyboard3(keycode, list);
}

int		ft_keyboard(int keycode, t_list *list)
{
	list->movespeed = 0.4;
	list->rotspeed = 0.25;
	ft_keyboard2(keycode, list);
	if (keycode == 124) //fleche de droite, tourner la camera vers la droite
	{
		list->oldDirX = list->dirX;
		list->dirX = list->dirX * cos(list->rotspeed) -
			list->dirY * sin(list->rotspeed);
		list->dirY = list->oldDirX * sin(list->rotspeed) +
			list->dirY * cos(list->rotspeed);
		list->oldPlaneX = list->planeX;
		list->planeX = list->planeX * cos(list->rotspeed) -
			list->planeY * sin(list->rotspeed);
		list->planeY = list->oldPlaneX * sin(list->rotspeed) +
			list->planeY * cos(list->rotspeed);
	}
	ft_raycasting(list);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, 0, 0);
	return (0);
}

void	ft_readKeys(t_list *list)
{
	mlx_hook(list->mlx_win, 2, 1L << 0, ft_keyboard, list);
	mlx_hook(list->mlx_win, 17, 1L << 17, ft_esc, (void*)list);
//	mlx_hook(list->mlx_win, 15, 1L << 16, visi, list);
}

