#include "../include/cub3d.h"

void    ft_dataPosition2(t_list *list, int a, int b)
{
    if (list->map[a][b] == 'N')
    {
        list->planeX = 0.66;
        list->planeY = 0;
        list->dirX = 0;
        list->dirY = -1;
        list->position = 1;
    }
    if (list->map[a][b] == 'S')
    {
        list->planeX = -0.66;
        list->planeY = 0;
        list->dirX = 0;
        list->dirY = 1;
        list->position = 1;
    }
    list->map[a][b] = '0';
    list->comptPos = 1;
}

void    ft_dataPosition(t_list *list, int a, int b)
{
    list->posY = a + 0.5;
    list->posX = b + 0.5;
    if (list->map[a][b] == 'E')
    {
        list->planeX = 0;
        list->planeY = 0.66;
        list->dirX = 1;
        list->dirY = 0;
        list->position = 1;
    }
    if (list->map[a][b] == 'W')
    {
        list->planeX = 0;
        list->planeY = -0.66;
        list->dirX = -1;
        list->dirY = 0;
        list->position = 1;
    }
    ft_dataPosition2(list, a, b);
}

int     ft_checkErrorPos(t_list *list, int a, int b)
{
    if ((list->comptPos == 0) && (list->map[a][b] == 'N' || list->map[a][b] == 'S' ||
        list->map[a][b] == 'E' || list->map[a][b] == 'W'))
    {
        if (ft_checkSpace(list, a, b) == -1)
        {
            write(1, "Position Error\n", 15);
            return (-1);
        }
        ft_dataPosition(list, a, b);
    }
    else
    {
        write(1, "Position Error\n", 15);
        return (-1);
    }
    return (1);
}

int     ft_checkpos(t_list *list)
{
    int a;
    int b;

    a = 0;
    while (list->map != '\0' && list->map[a] != '\0')
    {
        b = 0;
        while (list->map[a][b] != '\0')
        {
            if (ft_isalpha(list->map[a][b]))
                if (ft_checkErrorPos(list, a, b) == -1)
                    return (-1);
            b++;
        }
        a++;
    }
    if (list->position != 1)
    {
        write(1, "Position Error\n", 15);
        return (-1);
    }
    return (1);
}