#include "../include/cub3d.h"

int		ft_wallTexture(t_list *list)
{
	if (list->side == 0)
		list->wallX = list->posY + list->perpWallDist * list->rayDirY;
	else
		list->wallX = list->posX + list->perpWallDist * list->rayDirX;
	list->wallX -= floor((list->wallX));
	list->texX = (int)(list->wallX * (double)list->texWidth);
	if (list->side == 0 && list->rayDirX > 0)
		list->texX = list->texWidth - list->texX - 1;
	if (list->side == 1 && list->rayDirY < 0)
		list->texX = list->texWidth - list->texX - 1;
	list->step = 1.0 * list->texWidth / list->lineHeight;
	list->texPos = (list->drawStart - list->screenHeight / 2 +
			list->lineHeight / 2) * list->step;
	return (0);
}

void	ft_verline2(t_list *list, int a, int b)
{
		list->texY = (int)list->texPos & (list->texHeight - 1);
		list->texPos += list->step;
		if (list->side == 1 && list->rayDirY < 0)
			list->color = list->addrNO[list->texHeight * list->texY + list->texX];
		if (list->side == 1 && list->rayDirY > 0)
			list->color = list->addrSO[list->texHeight * list->texY + list->texX];
		if (list->side == 0 && list->rayDirX < 0)
			list->color = list->addrWE[list->texHeight * list->texY + list->texX];
		if (list->side == 0 && list->rayDirX > 0)
			list->color = list->addrEA[list->texHeight * list->texY + list->texX];
		list->addr[b * list->screenWidth + a] = list->color;
}

void	ft_verline(t_list *list, int a)
{
	int	b;

	b = 0;
	while (b < list->drawStart)
	{
		list->addr[b * list->screenWidth + a] = list->color_sky;
		b++;
	}
	while (b <= list->drawEnd)
	{
		ft_verline2(list, a, b);
		b++;
	}
	while (b < list->screenHeight)
	{
		list->addr[b * list->screenWidth + a] = list->color_floor;
		b++;
	}
}