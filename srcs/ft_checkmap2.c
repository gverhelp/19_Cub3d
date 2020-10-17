#include "../include/cub3d.h"

void    ft_addSpace3(t_list *list, int a)
{
    char    *tmp;

    tmp = NULL;
    list->map[a] = ft_strjoin(list->map[a], " ");
    free(tmp);
}

void     ft_addSpace(t_list *list)
{
    int a;
    int b;
    int c;

    a = 1;
    b = 0;
    c = 0;
    while (list->map && list->map[a])
    {
        if (ft_strlen(list->map[a - 1]) < ft_strlen(list->map[a]))
        {
            b = ft_strlen(list->map[a]) - ft_strlen(list->map[a - 1]);
            while (c < b)
            {
                ft_addSpace3(list, a - 1);
                c++;
            }
        }
        ft_addSpace2(list, a);
        a++;
    }
}

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
        if (list->map[a][b] != '1')
            return (-1);
        a++;
    }
    ft_addSpace(list);
    return (0);
}

int     ft_checkIfHole(t_list *list)
{
    int a;
    int b;

    a = 0;
    while (list->map && list->map[a + 1])
    {
        b = 0;
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