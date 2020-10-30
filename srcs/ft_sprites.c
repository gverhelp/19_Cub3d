#include "../include/cub3d.h"

void	ft_calculate_draw_start_end(t_list *list)
{
	list->spriteHeight = (int)fabs((double)list->screenHeight /
		list->transformY);
	list->drawStartY = -list->spriteHeight / 2 + list->screenHeight / 2;
    if (list->drawStartY < 0)
		list->drawStartY = 0;
    list->drawEndY = list->spriteHeight / 2 + list->screenHeight / 2;
    if (list->drawEndY >= list->screenHeight)
		list->drawEndY = list->screenHeight - 1;
	list->spriteWidth = (int)fabs((double)list->screenHeight
		/ list->transformY);
	list->drawStartX = -list->spriteWidth / 2 + list->spriteScreenX;
    if (list->drawStartX < 0)
		list->drawStartX = 0;
	list->drawEndX = list->spriteWidth / 2 + list->spriteScreenX;
    if (list->drawEndX >= list->screenWidth)
		list->drawEndX = list->screenWidth - 1;
}


void	ft_calculate_transform(t_list *list, int a)
{
	list->sprtX = list->spritesX[a] - list->posX;
	list->sprtY = list->spritesY[a] - list->posY;
	list->invdet = 1.0 / (list->planeX * list->dirY
		- list->dirX * list->planeY);
	list->transformX = list->invdet * (list->dirY *
		list->sprtX - list->dirX * list->sprtY);
	list->transformY = list->invdet * (-list->planeY *
		list->sprtX + list->planeX * list->sprtY);
	list->spriteScreenX = (int)((list->screenWidth / 2) *
		(1 + list->transformX / list->transformY));
}

void	ft_switch_sprites(t_list *list, int a, int b)
{
	double  tmp_x;
	double  tmp_y;

	tmp_x = list->spritesX[a];
	tmp_y = list->spritesY[a];
	list->spritesX[a] = list->spritesX[b];
	list->spritesY[a] = list->spritesY[b];
	list->spritesX[b] = tmp_x;
	list->spritesY[b] = tmp_y;
}

void	ft_sort_sprite(t_list *list)
{
	int		a;
	int		b;

	a = 0;
	while (a < list->nbSprites - 1)
	{
		list->spriteDistance = ((list->posX - list->spritesX[a]) *
			(list->posX - list->spritesX[a]) +
			(list->posY - list->spritesY[a]) *
			(list->posY - list->spritesY[a]));
		b = a + 1;
		while (b < list->nbSprites)
		{
			if (((list->posX - list->spritesX[b]) *
                (list->posX - list->spritesX[b]) +
                (list->posY - list->spritesY[b]) *
                (list->posY - list->spritesY[b])) > list->spriteDistance)
				ft_switch_sprites(list, a, b);
			b++;
		}
		a++;
	}
}

void        ft_raycasting_sprites(t_list *list)
{
    int     a;

    a = 0;
    ft_sort_sprite(list);
    while (a < list->nbSprites)
    {
        ft_calculate_transform(list, a);
        ft_calculate_draw_start_end(list);
        ft_verline_sprites(list);
        a++;
    }
}