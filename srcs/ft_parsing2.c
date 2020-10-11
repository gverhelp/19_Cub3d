
#include "../include/cub3d.h"

int     ft_checkTxTError(t_list *list)
{
    if (ft_checkpos(list) == -1)
    {
        write(1, "Error\nPosition Error\n", 21);
        return (-1);
    }
    if (ft_checkScreen(list) == -1)
    {
        write(1, "Error\nScreen Error\n", 19);
        return (-1);
    }
    if (ft_checkSkyFloor(list) == -1)
    {
        write(1, "Error\nError sky or floor\n", 25);
        return (-1);
    }
    if (ft_checkMap(list) == -1)
    {
        write(1, "Error\nError in map\n", 19);
        return (-1);
    }
    return (0);
}

int     ft_map(t_list *list)
{
    char   *tmp;

    tmp = NULL;
    tmp = list->tmpmap;
    list->map = ft_split(tmp, '\n');
    free(tmp);
    //rajouter newmap? (voir alessio)
    if (ft_checkTxTError(list) == -1)
        return (-1);
    return (1);
}

int     ft_check(t_list *list)
{
    if (!list->size)
        return (-1);
    if (list->aParsing < 8)
    {
        write(1, "Error\nError Number of Texture\n", 30);
        return (-1);
    }
    if (list->bParsing < 3)
    {
        write(1, "Error\nError in map\n", 19);
        return (-1);
    }
    if (ft_map(list) == -1)
        return (-1);
    return (1);
}
