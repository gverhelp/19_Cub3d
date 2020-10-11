#include "../include/cub3d.h"

void    ft_addSpace2(t_list *list, int a)
{
    int b;
    int c;

    if (ft_strlen(list->map[a - 1]) > ft_strlen(list->map[a]))
    {
        b = ft_strlen(list->map[a - 1]) - ft_strlen(list->map[a]);
        c = 0;
        while (c < b)
        {
            ft_addSpace3(list, a);
            c++;
        }
    }
}