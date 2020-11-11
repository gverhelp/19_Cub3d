/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:39 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:48:52 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_raycast4(t_list *list)
{
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect)
	if (list->side == 0)
		list->perpwalldist = (list->mapx - list->posx +
		(1 - list->stepx) / 2) / list->raydirx;
	else
		list->perpwalldist = (list->mapy - list->posy +
		(1 - list->stepy) / 2) / list->raydiry;
	//Calculate height ofl ine to draw on screen
	list->lineheight = (int)(list->screenheight / list->perpwalldist);
	//Calculate lowest and highest pixel to fill in current stripe
	list->drawstart = -list->lineheight / 2 + list->screenheight / 2;
	if (list->drawstart < 0)
		list->drawstart = 0;
	list->drawend = list->lineheight / 2 + list->screenheight / 2;
	if (list->drawend >= list->screenheight)
		list->drawend = list->screenheight - 1;
}

void	ft_raycast3(t_list *list)
{
	//jump to next map square, OR in x-direction, OR, in y-direction
	while (list->hit == 0)
	{
		if (list->sidedistx < list->sidedisty)
		{
			list->sidedistx += list->deltadistx;
			list->mapx += list->stepx;
			list->side = 0;
		}
		else
		{
			list->sidedisty += list->deltadisty;
			list->mapy += list->stepy;
			list->side = 1;
		}
		//Check if ray has hit a wall
		if (list->map[list->mapy][list->mapx] == '1')
			list->hit = 1;
	}
}

void	ft_raycast2(t_list *list)
{
	//calculate step and initial sideDist
	if (list->raydirx < 0)
	{
		list->stepx = -1;
		list->sidedistx = (list->posx - list->mapx) * list->deltadistx;
	}
	else
	{
		list->stepx = 1;
		list->sidedistx = (list->mapx + 1.0 - list->posx) * list->deltadistx;
	}
	if (list->raydiry < 0)
	{
		list->stepy = -1;
		list->sidedisty = (list->posy - list->mapy) * list->deltadisty;
	}
	else
	{
		list->stepy = 1;
		list->sidedisty = (list->mapy + 1.0 - list->posy) * list->deltadisty;
	}
}

void	ft_raycast(t_list *list, int a)
{
	//calculate ray position and direction
	list->camerax = 2 * a / (double)list->screenwidth - 1; //x-coordinate in camera space
	list->raydirx = list->dirx + list->planex * list->camerax;
	list->raydiry = list->diry + list->planey * list->camerax;

	//which box of the map we're in
	list->mapx = (int)list->posx;
	list->mapy = (int)list->posy;

	//sideDist are the length of ray from current position to next x or y-side
	//length of ray from one x or y-side to next x or y-side
	list->deltadistx = fabs(1 / list->raydirx);
	list->deltadisty = fabs(1 / list->raydiry);
	list->hit = 0; //what direction to stop in x or y-direction (either +1 or -1)
}

int	ft_raycasting(t_list *list)
{
	int a;

	a = 0;
	if (!(list->zbuffer = malloc(sizeof(int *) * list->screenwidth + 1)))
	{
		write(1, "Error\nzbuffer malloc did not work\n", 34);
		return (-1);
	}
	while (a < list->screenwidth)
	{
		ft_raycast(list, a);
		ft_raycast2(list);
		ft_raycast3(list);
		ft_raycast4(list);
		ft_walltexture(list);
		ft_verline(list, a);
		list->zbuffer[a] = list->perpwalldist;
		a++;
	}
	ft_raycasting_sprites(list);
	mlx_put_image_to_window(list->mlx, list->mlx_win, list->img, 0, 0);
	free(list->zbuffer);
	return (0);
}
