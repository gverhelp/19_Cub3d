#include "../include/cub3d.h"

int		ft_nbSprites(t_list *list)
{
	int		a;
	int		b;

	a = 0;
	if (!list->map)
		return (-1);
	while (list->map[a] != 0)
	{
		b = 0;
		while (list->map[a][b] != 0)
		{
			if (list->map[a][b] == '2')
			{
				list->nbSprites += 1;
			}
			b++;
		}
		a++;
	}
	return (0);
}

void	ft_get_sprites(t_list *list)
{
	int		a;
	int		b;
	int		c;

	a = 0;
	c = 0;
	while (list->map[a] != 0)
	{
		b = 0;
		while (list->map[a][b] != 0)
		{
			if (list->map[a][b] == '2')
			{
				list->spritesX[c] = b + 0.5;
				list->spritesY[c] = a + 0.5;
				c++;
			}
			b++;
		}
		a++;
	}
	list->spritesX[c] = '\0';
	list->spritesY[c] = '\0';
}

int		ft_parsingSprites(t_list *list)
{
	if (ft_nbSprites(list) == -1)
		return (-1);
	if (!(list->spritesX = malloc(sizeof(int *) * list->nbSprites + 1)))
		return (-1);
	if (!(list->spritesY = malloc(sizeof(int *) * list->nbSprites + 1)))
		return (-1);
    ft_get_sprites(list);
	return (0);
}