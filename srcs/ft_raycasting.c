#include "../include/cub3d.h"

void    ft_raycast4(t_list *list, int a)
{
    //Calculate distance projected on camera direction (Euclidean distance will give fisheye effect)
	if (list->side == 0)
		list->perpWallDist = (list->mapX - list->posX + (1 - list->stepX) / 2) / list->rayDirX;
	else
		list->perpWallDist = (list->mapY - list->posY + (1 - list->stepY) / 2) / list->rayDirY;
    //Calculate height ofl ine to draw on screen
	list->lineHeight = (int)(list->screenHeight / list->perpWallDist);
	//Calculate lowest and highest pixel to fill in current stripe
	list->drawStart = -list->lineHeight / 2 + list->screenHeight / 2;
	if (list->drawStart < 0)
		list->drawStart = 0;
	list->drawEnd = list->lineHeight / 2 + list->screenHeight / 2;
	if (list->drawEnd >= list->screenHeight)
		list->drawEnd = list->screenHeight - 1;
    ft_verline(list, a);
}

void    ft_raycast3(t_list *list, int a)
{
    //jump to next map square, OR in x-direction, OR, in y-direction
	while (list->hit == 0)
	{
		if (list->sideDistX < list->sideDistY)
		{
			list->sideDistX += list->deltaDistX;
			list->mapX += list->stepX;
			list->side = 0;
		}
		else
		{
			list->sideDistY += list->deltaDistY;
			list->mapY += list->stepY;
			list->side = 1;
		}
		//Check if ray has hit a wall
		if (list->map[list->mapY][list->mapX] == '1')
			list->hit = 1;
	}
    ft_raycast4(list, a);
}

void    ft_raycast2(t_list *list, int a)
{
    //calculate step and initial sideDist
	if (list->rayDirX < 0)
	{
		list->stepX = -1;
		list->sideDistX = (list->posX - list->mapX) * list->deltaDistX;
	}
	else
	{
		list->stepX = 1;
		list->sideDistX = (list->mapX + 1.0 - list->posX) * list->deltaDistX;
	}
	if (list->rayDirY < 0)
	{
		list->stepY = -1;
		list->sideDistY = (list->posY - list->mapY) * list->deltaDistY;
	}
	else
	{
		list->stepY = 1;
		list->sideDistY = (list->mapY + 1.0 - list->posY) * list->deltaDistY;
	}
    ft_raycast3(list, a);
}

void    ft_raycast(t_list *list, int a)
{
    //calculate ray position and direction
	list->cameraX = 2 * a / (double)list->screenWidth - 1; //x-coordinate in camera space
	list->rayDirX = list->dirX + list->planeX * list->cameraX;
	list->rayDirY = list->dirY + list->planeY * list->cameraX;

	//which box of the map we're in
	list->mapX = (int)list->posX;
	list->mapY = (int)list->posY;

	//sideDist are the length of ray from current position to next x or y-side
	//length of ray from one x or y-side to next x or y-side
	list->deltaDistX = fabs(1 / list->rayDirX);
	list->deltaDistY = fabs(1 / list->rayDirY);
	list->hit = 0; //what direction to stop in x or y-direction (either +1 or -1)
    ft_raycast2(list, a);
}

int     ft_raycasting(t_list *list)
{
    int a;

    a = 0;
    ft_init_colors(list);
 //   if (!(list->zbuffer = malloc(sizeof(int *) * list->screenWidth + 1)))
 //       return (-1);
    while (a < list->screenWidth)
    {
        ft_raycast(list, a);
        a++;
    }
    //sprites + save (voir chez Alessio)
  //  free(list->zbuffer);
    return (0);
}