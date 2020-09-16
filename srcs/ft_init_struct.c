/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:15:25 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/09 18:30:54 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_list(t_list *list)
{
	list->img = 0;
	list->mlx = 0;
	list->mlx_win = 0;
	list->addr = 0;
	list->bits_per_pixel = 0;
	list->line_length = 0;
	list->endian = 0;
	list->posX = 22;
	list->posY = 12;
	list->dirX = -1;
	list->dirY = 0;
	list->planeX = 0;
	list->planeY = 0.66;
	list->time = 0;
	list->oldTime = 0;
	list->cameraX = 0;
	list->rayDirX = 0;
	list->rayDirY = 0;
	list->mapX = 0;
	list->mapY = 0;
	list->sideDistX = 0;
	list->sideDistY = 0;
	list->stepX = 0;
	list->stepY = 0;
}

void	ft_init_list2(t_list *list)
{
	list->hit = 0;
	list->side = 0;
	list->deltaDistX = 0;
	list->deltaDistY = 0;
	list->perpWallDist = 0;
	list->lineHeight = 0;
	list->drawStart = 0;
	list->drawEnd = 0;
	list->color_floor = 0;
	list->color_sky = 0;
	list->color_wall_w = 0;
	list->color_wall_e = 0;
	list->color_wall_s = 0;
	list->color_wall_n = 0;
	list->savebmp = 0;
	list->size = ft_strdup("");
	list->textN = ft_strdup("");
	list->textS = ft_strdup("");
	list->textE = ft_strdup("");
	list->textW = ft_strdup("");
	list->textSprite = ft_strdup("");
	list->textF = ft_strdup("");
	list->textC = ft_strdup("");
}
