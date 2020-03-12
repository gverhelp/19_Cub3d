/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 17:56:44 by gverhelp          #+#    #+#             */
/*   Updated: 2020/03/11 18:33:43 by gverhelp         ###   ########.fr       */
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

void	ft_calculate_ray_and_deltaDist(t_data *data, int a)
{
	//calculate ray position and direction
	data->cameraX = 2 * a / (float)screenWidth - 1; //x-coordinate in camera space
	data->rayDirX = data->dirX + data->planeX * data->cameraX;
	data->rayDirY = data->dirY + data->planeY * data->cameraX;

	//which box of the map we're in
	data->mapX = (int)data->posX;
	data->mapY = (int)data->posY;

	//sideDist are the length of ray from current position to next x or y-side
	//length of ray from one x or y-side to next x or y-side
	data->deltaDistX = fabs(1 / data->rayDirX);
	data->deltaDistY = fabs(1 / data->rayDirY);
}

void	ft_calculate_step_and_sideDist(t_data *data)
{
	//calculate step and initial sideDist
	if (data->rayDirX < 0)
	{
		data->stepX = -1;
		data->sideDistX = (data->posX - data->mapX) * data->deltaDistX;
	}
	else
	{
		data->stepX = 1;
		data->sideDistX = (data->mapX + 1.0 - data->posX) * data->deltaDistX;
	}
	if (data->rayDirY < 0)
	{
		data->stepY = -1;
		data->sideDistY = (data->posY - data->mapY) * data->deltaDistY;
	}
	else
	{
		data->stepY = 1;
		data->sideDistY = (data->mapY + 1.0 - data->posY) * data->deltaDistY;
	}
}

void	ft_perform_dda(t_data *data)
{
	//jump to next map square, OR in x-direction, OR, in y-direction
	while (data->hit == 0)
	{
		if (data->sideDistX < data->sideDistY)
		{
			data->sideDistX += data->deltaDistX;
			data->mapX += data->stepX;
			data->side = 0;
		}
		else
		{
			data->sideDistY += data->deltaDistY;
			data->mapY += data->stepY;
			data->side = 1;
		}
		//Check if ray has hit a wall
		if (worldMap[data->mapX][data->mapY] > 0)
			data->hit = 1;
	}
}

void	ft_calculate_dist(t_data *data)
{
	//Calculate distance projected on camera direction (Euclidean distance will give fisheye effect)
	if (data->side == 0)
		data->perpWallDist = (data->mapX - data->posX + (1 - data->stepX) / 2) / data->rayDirX;
	else
		data->perpWallDist = (data->mapY - data->posY + (1 - data->stepY) / 2) / data->rayDirY;
}

void	ft_calculate_height_wall(t_data *data)
{
	//Calculate height ofl ine to draw on screen
	data->lineHeight = (int)(screenHeight / data->perpWallDist);

	//Calculate lowest and highest pixel to fill in current stripe
	data->drawStart = -data->lineHeight / 2 + screenHeight / 2;
	if (data->drawStart < 0)
		data->drawStart = 0;
	data->drawEnd = data->lineHeight / 2 + screenHeight / 2;
	if (data->drawEnd >= screenHeight)
		data->drawEnd = screenHeight - 1;
}

void	ft_verline(t_data *data, int a)
{
	int	y;

	y = 0;
	while (y < data->drawStart)
	{
		data->addr[y * screenWidth + a] = data->color_floor;
		y++;
	}
	while (y < data->drawEnd)
	{
		//if (data->side == 0 && data->rayDirX <= 0)
		//	data->addr[y * screenWidth + a] = data->color_wall_w;
		//if (data->side == 0 && data->rayDirY > 0)
			data->addr[y * screenWidth + a] = data->color_wall_e;
		//if (data->side == 1 && data->rayDirY > 0)
		//	data->addr[y * screenWidth + a] = data->color_wall_s;
		//if (data->side == 1 && data->rayDirY <= 0)
		//	data->addr[y * screenWidth + a] = data->color_wall_n;
		y++;
	}
	while (y < screenHeight)
	{
		data->addr[y * screenWidth + a] = data->color_sky;
		y++;
	}
}

void	ft_init_colors(t_data *data)
{
	data->color_sky = 65536 * 200 + 256 * 200 + 25;
	data->color_wall_n = 65536 * 200 + 256 * 50 + 25;
	data->color_wall_s = 65536 * 150 + 256 * 100 + 25;
	data->color_wall_e = 65536 * 100 + 256 * 150 + 25;
	data->color_wall_w = 65536 * 50 + + 256 * 200 + 25;
	data->color_floor = 65536 * 200 + 256 * 175 + 150;
}
