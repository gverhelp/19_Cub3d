/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:33 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:37:46 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_keyboard4(int keycode, t_list *list)
{
	if (keycode == 123) //fleche de gauche, tourner la camera vers la gauche
	{
		list->olddirx = list->dirx;
		list->dirx = list->dirx * cos(-(list->rotspeed)) - list->diry *
			sin(-(list->rotspeed));
		list->diry = list->olddirx * sin(-(list->rotspeed)) + list->diry *
			cos(-(list->rotspeed));
		list->oldplanex = list->planex;
		list->planex = list->planex * cos(-(list->rotspeed)) - list->planey *
			sin(-(list->rotspeed));
		list->planey = list->oldplanex * sin(-(list->rotspeed)) + list->planey *
			cos(-(list->rotspeed));
	}
	if (keycode == 53)
	{
		ft_exit(list);
		exit(0);
	}
}

void	ft_keyboard3(int keycode, t_list *list)
{
	if (keycode == 2) //straff vers la droite avec D
	{
		if (list->map[(int)(list->posy +
			list->dirx * 0.5)][(int)list->posx] != '1')
			list->posy += list->dirx * list->movespeed;
		if (list->map[(int)list->posy][(int)(list->posx -
			list->diry * 0.5)] != '1')
			list->posx -= list->diry * list->movespeed;
	}
	if (keycode == 0) //straff vers la gauche avec Q
	{
		if (list->map[(int)(list->posy -
			list->dirx * 0.5)][(int)list->posx] != '1')
			list->posy -= list->dirx * list->movespeed;
		if (list->map[(int)list->posy][(int)(list->posx +
			list->diry * 0.5)] != '1')
			list->posx += list->diry * list->movespeed;
	}
	ft_keyboard4(keycode, list);
}

void	ft_keyboard2(int keycode, t_list *list)
{
	if (keycode == 13 || keycode == 126) //avancer avec fleche du haut (126) ou Z (13)
	{
		if (list->map[(int)list->posy][(int)(list->posx + list->dirx *
					list->movespeed)] != '1')
			list->posx += list->dirx * list->movespeed;
		if (list->map[(int)(list->posy + list->diry * list->movespeed)]
				[(int)list->posx] != '1')
			list->posy += list->diry * list->movespeed;
	}
	if (keycode == 1 || keycode == 125) //reculer avec fleche du bas (125) ou S (1)
	{
		if (list->map[(int)list->posy][(int)(list->posx - list->dirx *
					list->movespeed)] != '1')
			list->posx -= list->dirx * list->movespeed;
		if (list->map[(int)(list->posy - list->diry * list->movespeed)]
				[(int)list->posx] != '1')
			list->posy -= list->diry * list->movespeed;
	}
	ft_keyboard3(keycode, list);
}

int	ft_keyboard(int keycode, t_list *list)
{
	list->movespeed = 0.2; //0.4
	list->rotspeed = 0.17; //0.25
	if (keycode == 124) //fleche de droite, tourner la camera vers la droite
	{
		list->olddirx = list->dirx;
		list->dirx = list->dirx * cos(list->rotspeed) -
			list->diry * sin(list->rotspeed);
		list->diry = list->olddirx * sin(list->rotspeed) +
			list->diry * cos(list->rotspeed);
		list->oldplanex = list->planex;
		list->planex = list->planex * cos(list->rotspeed) -
			list->planey * sin(list->rotspeed);
		list->planey = list->oldplanex * sin(list->rotspeed) +
			list->planey * cos(list->rotspeed);
	}
	ft_keyboard2(keycode, list);
	if (ft_raycasting(list) == -1)
		return (ft_exit(list));
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, 0, 0);
	return (0);
}

void	ft_readkeys(t_list *list)
{
	mlx_hook(list->mlx_win, 2, 1L << 0, ft_keyboard, list);
	mlx_hook(list->mlx_win, 17, 1L << 17, ft_esc, (void*)list);
	//	mlx_hook(list->mlx_win, 15, 1L << 16, visi, list);
}

