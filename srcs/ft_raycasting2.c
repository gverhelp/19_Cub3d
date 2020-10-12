#include "../include/cub3d.h"

void	ft_init_colors(t_list *list)
{
//	list->color_sky = 65536 * 200 + 256 * 200 + 25;
	list->color_wall_n = 65536 * 200 + 256 * 50 + 25;
	list->color_wall_s = 65536 * 150 + 256 * 100 + 25;
	list->color_wall_e = 65536 * 100 + 256 * 150 + 25;
	list->color_wall_w = 65536 * 50 + + 256 * 200 + 25;
//	list->color_floor = 65536 * 200 + 256 * 175 + 150;
}

void	ft_verline(t_list *list, int a)
{
	int	y;

	y = 0;
	while (y < list->drawStart)
	{
		list->addr[y * list->screenWidth + a] = list->color_sky;
		y++;
	}
	while (y < list->drawEnd)
	{
//		if (list->side == 0 && list->rayDirX <= 0) //<=
//			list->addr[y * list->screenWidth + a] = list->color_wall_w;
//		if (list->side == 0 && list->rayDirY > 0) //>
//			list->addr[y * list->screenWidth + a] = list->color_wall_e;
//		if (list->side == 1 && list->rayDirY > 0) //>
//			list->addr[y * list->screenWidth + a] = list->color_wall_s;
//		if (list->side == 1 && list->rayDirY <= 0) //<=
			list->addr[y * list->screenWidth + a] = list->color_wall_n;
		y++;
	}
	while (y < list->screenHeight)
	{
		list->addr[y * list->screenWidth + a] = list->color_floor;
		y++;
	}
}