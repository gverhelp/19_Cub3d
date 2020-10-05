#include "../include/cub3d.h"

int     ft_checkSkyFloor3(t_list *list, char *str, int a)
{
    while (ft_isdigit(str[a]))
        a++;
    if (str[a] == ',')
        a++;
    if ((!ft_isdigit(str[a])) ||
        ((str[a] == '0' && ft_isdigit(str[a + 1]))))
        return (-1);
    list->b = ft_atoi(&str[a]);
    while (ft_isdigit(str[a]))
        a++;
    if (str[a] != '\0')
        return (-1);
    if (list->r < 0 || list->r > 255 || list->g < 0 ||
        list->g > 255 || list->b < 0 || list->b > 255)
        return (-1);
    return (0);
}

int     ft_checkSkyFloor2(t_list *list, char *str)
{
    int a;

    a = 1;
    if (ft_strchr(str, '-'))
        return (-1);
    while (str[a] == ' ')
        a++;
    if ((!ft_isdigit(str[a])) ||
        ((str[a] == '0' && ft_isdigit(str[a + 1]))))
        return (-1);
    list->r = ft_atoi(&str[a]);
    while(ft_isdigit(str[a]))
        a++;
    if (str[a] == ',')
        a++;
    if ((!ft_isdigit(str[a])) ||
        ((str[a] == '0' && ft_isdigit(str[a + 1]))))
        return (-1);
    list->g = ft_atoi(&str[a]);
    ft_checkSkyFloor3(list, str, a);
    return (0);
}

int    ft_hexa(t_list *list)
{
//    list->r *= 2^16;
//    list->g *= 2^8;
    return (list->r << 16 | list->g << 8 | list->b);
}

int     ft_checkSkyFloor(t_list *list)
{
    //maybe ajouter one->fo et one->co chez Alessio
    if (ft_checkSkyFloor2(list, list->textF) == -1)
        return (-1);
    list->color_floor = ft_hexa(list);
    if (ft_checkSkyFloor2(list, list->textC) == -1)
        return (-1);
    list->color_sky = ft_hexa(list);
    return (0);
}
