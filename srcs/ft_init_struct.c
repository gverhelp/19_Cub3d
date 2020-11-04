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

void	ft_init_list5(t_list *list)
{
	list->imgEA = 0;
	list->addrEA = 0;
	list->imgWE = 0;
	list->addrWE = 0;
	list->imgSO = 0;
	list->addrSO = 0;
}

void	ft_init_list4(t_list *list)
{
	list->texHeight = 0;
	list->texWidth = 0;
	list->aParsing = 0;
	list->bParsing = 0;
	list->spritesX = 0;
	list->spritesY = 0;
	list->nbSprites = 0;
	list->spriteDistance = 0;
	list->sprtX = 0;
	list->sprtY = 0;
	list->invdet = 0;
	list->transformX = 0;
	list->transformY = 0;
	list->spriteScreenX = 0;
	list->spriteHeight = 0;
	list->spriteWidth = 0;
	list->drawStartX = 0;
	list->drawStartY = 0;
	list->drawEndX = 0;
	list->drawEndY = 0;
	list->stripe = 0;
	list->imgSprite = 0;
	list->addrSprite = 0;
	ft_init_list5(list);
}

void	ft_init_list3(t_list *list)
{
	list->stepY = 0;
	list->aParsing = 0;
	list->bParsing = 0;
	list->tmpmap = ft_strdup("");
	list->map = NULL;
	list->zbuffer = 0;
	list->position = 0;
	list->comptPos = 0;
	list->oldDirX = 0;
	list->oldPlaneX = 0;
	list->screenWidth = 0;
	list->screenHeight = 0;
	list->r = -1;
	list->g = -1;
	list->b = -1;
	list->texPos = 0;
	list->texX = 0;
	list->texY = 0;
	list->wallX = 0;
	list->imgNO = 0;
	list->addrNO = 0;
	list->color = 0;
	list->step = 0;
	ft_init_list4(list);
}

void	ft_init_list2(t_list *list)
{
	list->img = 0;
	list->mlx = 0;
	list->mlx_win = 0;
	list->addr = 0;
	list->bits_per_pixel = 0;
	list->line_length = 0;
	list->endian = 0;
	list->posX = 0;
	list->posY = 0;
	list->dirX = 0;
	list->dirY = 0;
	list->planeX = 0;
	list->planeY = 0;
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
	ft_init_list3(list);
}

void	ft_init_list(t_list *list)
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
	list->savebmp = 0;
	list->size = ft_strdup("");
	list->textNO = ft_strdup("");
	list->textSO = ft_strdup("");
	list->textEA = ft_strdup("");
	list->textWE = ft_strdup("");
	list->textSprite = ft_strdup("");
	list->textF = ft_strdup("");
	list->textC = ft_strdup("");
	ft_init_list2(list);
}