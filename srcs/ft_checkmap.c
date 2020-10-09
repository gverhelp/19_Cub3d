#include "../include/cub3d.h"

int     ft_isspace(int c)
{
    if (c == ' ' || c == '\t' || c == '\r' ||
        c == '\n' || c == '\v' || c == '\f')
        return (1);
    return (0);
}

int     ft_checkLastLine(t_list *list)
{
    int a;
    int b;

    a = 0;
    b = 0;
    while (list->map[a])
        a++;
    while (list->map[a - 1][b] == ' ')
        b++;
    if (list->map[a - 1][b] != '1')
        return (-1);
    while (list->map[a - 1][b])
    {
        if (list->map[a - 1][b] != '1' && list->map[a - 1][b] != ' ')
            return (-1);
        b++;
    }
    return (0);
}

int     ft_checkFirstLine(t_list *list)
{
    int a;

    a = 0;
    while (list->map[0][a] == ' ')
        a++;
    if (list->map[0][a] != '1')
        return (-1);
    while (list->map[0][a])
    {
        if (list->map[0][a] != '1' && list->map[0][a] != ' ')
            return (-1);
        a++;
    }
    return (0);
}

int     ft_checkCharacters(t_list *list)
{
    int a;
    int b;

    a = 0;
    while (list->map != '\0' && list->map[a] != '\0')
    {
        b = 0;
        while (list->map[a][b] != '\0')
        {
            if (list->map[a][b] != '0' && list->map[a][b] != '1'
                && list->map[a][b] != '2' && list->map[a][b] != 'N'
                && list->map[a][b] != 'S' && list->map[a][b] != 'E'
                && list->map[a][b] != 'W' && (ft_isspace(list->map[a][b]) == 0))
                return (-1);
            b++;
        }
        a++;
    }
    return (0);
}

int     ft_checkMap(t_list *list)
{
    if (ft_checkCharacters(list) == -1)
        return (-1);
    if (ft_checkFirstLine(list) == -1)
        return (-1);
    if (ft_checkLastLine(list) == -1)
        return (-1);
    if (ft_checkFirstColumn(list) == -1)
        return (-1);
    if (ft_checkLastColumn(list) == -1)
        return (-1);
    if (ft_checkIfHole(list) == -1)
        return (-1);
    return (0);
}