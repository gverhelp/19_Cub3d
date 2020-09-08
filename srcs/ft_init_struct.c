/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 14:15:25 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/08 18:59:57 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_list(t_data *data)
{
	data->img = 0;
	data->mlx = 0;
	data->mlx_win = 0;
	data->addr = 0;
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->endian = 0;
	data->posX = 22;
	data->posY = 12;
	data->dirX = -1;
	data->dirY = 0;
	data->planeX = 0;
	data->planeY = 0.66;
	data->time = 0;
	data->oldTime = 0;
	data->cameraX = 0;
	data->rayDirX = 0;
	data->rayDirY = 0;
	data->mapX = 0;
	data->mapY = 0;
	data->sideDistX = 0;
	data->sideDistY = 0;
	data->stepX = 0;
	data->stepY = 0;
}

void	ft_init_list2(t_data *data)
{
	data->hit = 0;
	data->side = 0;
	data->deltaDistX = 0;
	data->deltaDistY = 0;
	data->perpWallDist = 0;
	data->lineHeight = 0;
	data->drawStart = 0;
	data->drawEnd = 0;
	data->color_floor = 0;
	data->color_sky = 0;
	data->color_wall_w = 0;
	data->color_wall_e = 0;
	data->color_wall_s = 0;
	data->color_wall_n = 0;
}

void	ft_init_list_parsing(t_data2 *data2)
{
	data2->size = ft_strdup("");
	data2->posN = ft_strdup("");
	data2->posS = ft_strdup("");
	data2->posE = ft_strdup("");
	data2->posW = ft_strdup("");
	data2->textS = ft_strdup("");
	data2->textF = ft_strdup("");
	data2->textC = ft_strdup("");
}
