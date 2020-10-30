#include "../include/cub3d.h"

void        ft_write_sprites(t_list *list)
{
    int		a;
    int		b;

    a = list->drawStartY;
	b = 0;
    while (a < list->drawEndY)
	{
		b = a * 256 - list->screenHeight * 128 +
			list->spriteHeight * 128;
		list->texY = ((b * 64) / list->spriteHeight) / 256;
        if ((list->addrSprite[64 * list->texY + list->texX] & 0x00FFFFFF) != 0)
			list->addr[a * list->screenWidth + list->stripe] =
                list->addrSprite[64 * list->texY + list->texX];
		a++;
	}
}

void        ft_verline_sprites(t_list *list)
{
    list->stripe = list->drawStartX;
    while (list->stripe < list->drawEndX)
	{
		list->texX = (int)((list->stripe - (-list->spriteWidth / 2
		+ list->spriteScreenX)) * 64 / list->spriteWidth);
        if (list->transformY > 0 && list->stripe > 0 &&
            list->stripe < list->screenWidth &&
            list->transformY < list->zbuffer[list->stripe] && list->texX < 64)
            ft_write_sprites(list);
		list->stripe++;
    }
}