/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:56:44 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/08 14:37:41 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int worldMap[mapWidth][mapHeight]=
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void	ft_calculate_ray_and_deltaDist(t_list *list, int a)
{
	//calculate ray position and direction
	list->cameraX = 2 * a / (float)screenWidth - 1; //x-coordinate in camera space
	list->rayDirX = list->dirX + list->planeX * list->cameraX;
	list->rayDirY = list->dirY + list->planeY * list->cameraX;

	//which box of the map we're in
	list->mapX = (int)list->posX;
	list->mapY = (int)list->posY;

	//sideDist are the length of ray from current position to next x or y-side
	//length of ray from one x or y-side to next x or y-side
	list->deltaDistX = fabs(1 / list->rayDirX);
	list->deltaDistY = fabs(1 / list->rayDirY);
}

void	ft_calculate_step_and_sideDist(t_list *list)
{
	//calculate step and initial sideDist
	if (list->rayDirX < 0)
	{
		list->stepX = -1;
		list->sideDistX = (list->posX - list->mapX) * list->deltaDistX;
	}
	else
	{
		list->stepX = 1;
		list->sideDistX = (list->mapX + 1.0 - list->posX) * list->deltaDistX;
	}
	if (list->rayDirY < 0)
	{
		list->stepY = -1;
		list->sideDistY = (list->posY - list->mapY) * list->deltaDistY;
	}
	else
	{
		list->stepY = 1;
		list->sideDistY = (list->mapY + 1.0 - list->posY) * list->deltaDistY;
	}
}

void	ft_perform_dda(t_list *list)
{
	//jump to next map square, OR in x-direction, OR, in y-direction
	while (list->hit == 0)
	{
		if (list->sideDistX < list->sideDistY)
		{
			list->sideDistX += list->deltaDistX;
			list->mapX += list->stepX;
			list->side = 0;
		}
		else
		{
			list->sideDistY += list->deltaDistY;
			list->mapY += list->stepY;
			list->side = 1;
		}
		//Check if ray has hit a wall
		if (worldMap[list->mapX][list->mapY] > 0)
			list->hit = 1;
	}
}

void	ft_calculate_dist(t_list *list)
{
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect)
	if (list->side == 0)
		list->perpWallDist = (list->mapX - list->posX + (1 - list->stepX) / 2) / list->rayDirX;
	else
		list->perpWallDist = (list->mapY - list->posY + (1 - list->stepY) / 2) / list->rayDirY;
}

void	ft_calculate_height_wall(t_list *list)
{
	//Calculate height ofl ine to draw on screen
	list->lineHeight = (int)(screenHeight / list->perpWallDist);

	//Calculate lowest and highest pixel to fill in current stripe
	list->drawStart = -list->lineHeight / 2 + screenHeight / 2;
	if (list->drawStart < 0)
		list->drawStart = 0;
	list->drawEnd = list->lineHeight / 2 + screenHeight / 2;
	if (list->drawEnd >= screenHeight)
		list->drawEnd = screenHeight - 1;
}

void	ft_verline(t_list *list, int a)
{
	int	y;

	y = 0;
	while (y < list->drawStart)
	{
		list->addr[y * screenWidth + a] = list->color_floor;
		y++;
	}
	while (y < list->drawEnd)
	{
		//if (list->side == 0 && list->rayDirX <= 0)
		//	list->addr[y * screenWidth + a] = list->color_wall_w;
		//if (list->side == 0 && list->rayDirY > 0)
			list->addr[y * screenWidth + a] = list->color_wall_e;
		//if (list->side == 1 && list->rayDirY > 0)
		//	list->addr[y * screenWidth + a] = list->color_wall_s;
		//if (list->side == 1 && list->rayDirY <= 0)
		//	list->addr[y * screenWidth + a] = list->color_wall_n;
		y++;
	}
	while (y < screenHeight)
	{
		list->addr[y * screenWidth + a] = list->color_sky;
		y++;
	}
}

void	ft_init_colors(t_list *list)
{
	list->color_sky = 65536 * 200 + 256 * 200 + 25;
	list->color_wall_n = 65536 * 200 + 256 * 50 + 25;
	list->color_wall_s = 65536 * 150 + 256 * 100 + 25;
	list->color_wall_e = 65536 * 100 + 256 * 150 + 25;
	list->color_wall_w = 65536 * 50 + + 256 * 200 + 25;
	list->color_floor = 65536 * 200 + 256 * 175 + 150;
}