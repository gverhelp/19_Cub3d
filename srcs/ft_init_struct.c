/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:09 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:32:49 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_init_list5(t_list *list)
{
	list->imgea = 0;
	list->addrea = 0;
	list->imgwe = 0;
	list->addrwe = 0;
	list->imgso = 0;
	list->addrso = 0;
}

void	ft_init_list4(t_list *list)
{
	list->texheight = 0;
	list->texwidth = 0;
	list->aparsing = 0;
	list->bparsing = 0;
	list->spritesx = 0;
	list->spritesy = 0;
	list->nbsprites = 0;
	list->spritedistance = 0;
	list->sprtx = 0;
	list->sprty = 0;
	list->invdet = 0;
	list->transformx = 0;
	list->transformy = 0;
	list->spritescreenx = 0;
	list->spriteheight = 0;
	list->spritewidth = 0;
	list->drawstartx = 0;
	list->drawstarty = 0;
	list->drawendx = 0;
	list->drawendy = 0;
	list->stripe = 0;
	list->imgsprite = 0;
	list->addrsprite = 0;
	ft_init_list5(list);
}

void	ft_init_list3(t_list *list)
{
	list->stepy = 0;
	list->aparsing = 0;
	list->bparsing = 0;
	list->tmpmap = ft_strdup("");
	list->map = NULL;
	list->zbuffer = 0;
	list->position = 0;
	list->comptpos = 0;
	list->olddirx = 0;
	list->oldplanex = 0;
	list->screenwidth = 0;
	list->screenheight = 0;
	list->r = -1;
	list->g = -1;
	list->b = -1;
	list->texpos = 0;
	list->texx = 0;
	list->texy = 0;
	list->wallx = 0;
	list->imgno = 0;
	list->addrno = 0;
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
	list->posx = 0;
	list->posy = 0;
	list->dirx = 0;
	list->diry = 0;
	list->planex = 0;
	list->planey = 0;
	list->time = 0;
	list->oldtime = 0;
	list->camerax = 0;
	list->raydirx = 0;
	list->raydiry = 0;
	list->mapx = 0;
	list->mapy = 0;
	list->sidedistx = 0;
	list->sidedisty = 0;
	list->stepx = 0;
	ft_init_list3(list);
}

void	ft_init_list(t_list *list)
{
	list->hit = 0;
	list->side = 0;
	list->deltadistx = 0;
	list->deltadisty = 0;
	list->perpwalldist = 0;
	list->lineheight = 0;
	list->drawstart = 0;
	list->drawend = 0;
	list->color_floor = 0;
	list->color_sky = 0;
	list->savebmp = 0;
	list->size = ft_strdup("");
	list->textno = ft_strdup("");
	list->textso = ft_strdup("");
	list->textea = ft_strdup("");
	list->textwe = ft_strdup("");
	list->textsprite = ft_strdup("");
	list->textf = ft_strdup("");
	list->textc = ft_strdup("");
	ft_init_list2(list);
}
