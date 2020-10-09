#include "../include/cub3d.h"

int     ft_checkFirstColumn(t_list *list)
{
    int a;
    int b;

    a = 0;
    while (list->map && list->map[a])
    {
        b = 0;
        while (list->map[a][b] == ' ')
            b++;
        if (list->map[a][b] != '1')
            return (-1);
        a++;
    }
    return (0);
}

int     ft_checkLastColumn(t_list *list)
{
    int a;
    int b;

    a = 0;
    while (list->map && list->map[a])
    {
        b = ft_strlen(list->map[a]) - 1;
        while (list->map[a][b] == ' ')
            b--;
        if (list->map[a][b] != '1')
            return (-1);
        a++;
    }
    return (0);
}

int     ft_checkIfHole(t_list *list)
{
    int a;
    int b;

    a = 1;
    while (list->map && list->map[a])
    {
        b = 1;
        while (list->map[a][b])
        {
            if (list->map[a][b] == '0' || list->map[a][b] == '2')
                if (ft_checkSpace(list, a, b) == -1)
                    return (-1);
            b++;
        }
        a++;
    }
    return (0);
}
