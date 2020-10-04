#include "../include/cub3d.h"

void     ft_checkMaxMinScreen(t_list *list)
{
    if (list->screenWidth > 1680)
        list->screenWidth = 1680;
    if (list->screenWidth < 720)
        list->screenWidth = 720;
    if (list->screenHeight > 1050)
        list->screenHeight = 1050;
    if (list->screenHeight < 480)
        list->screenHeight = 480;
}

int     ft_checkScreen(t_list *list)
{
    int a;

    a = 1;
    while (list->size[a] == ' ')
        a++;
    if (!ft_isdigit(list->size[a]) || list->size[a] == '0')
        return (-1);
    list->screenWidth = ft_atoi(&list->size[a]);
    while (ft_isdigit(list->size[a]))
        a++;
    while(list->size[a] == ' ')
        a++;
    if (!ft_isdigit(list->size[a]) || list->size[a] == '0')
        return (-1);
    list->screenHeight = ft_atoi(&list->size[a]);
    while(ft_isdigit(list->size[a]))
        a++;
    if (list->size[a] != '\0')
        return (-1);
    if (list->screenWidth <= 0 || list->screenHeight <= 0)
        return (-1);
    ft_checkMaxMinScreen(list);
    return (0);
}