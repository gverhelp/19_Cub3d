
#include "../include/cub3d.h"

int		ft_checkSpace(t_list *list, int a, int b)
{
	if (list->map[a][b - 1] == ' ')
		return (-1);
	if (list->map[a][b + 1] == ' ')
		return (-1);
	if (list->map[a + 1][b] == ' ')
		return (-1);
	if (list->map[a - 1][b] == ' ')
		return (-1);
	if (list->map[a - 1][b - 1] == ' ')
		return (-1);
	if (list->map[a + 1][b + 1] == ' ')
		return (-1);
	if (list->map[a + 1][b - 1] == ' ')
		return (-1);
	if (list->map[a - 1][b + 1] == ' ')
		return (-1);
	return (1);
}

int     ft_checkTxTError(t_list *list)
{
    if (ft_checkpos(list) == -1)
        return (-1);
    if (ft_checkScreen(list) == -1)
    {
        write(1, "Screen Error\n", 13);
        return (-1);
    }
    return (1);
}

int     ft_map(t_list *list)
{
    char   *tmp;

    tmp = NULL;
    tmp = list->tmpmap;
    list->map = ft_split(tmp, '\n');
    free(tmp);
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
        write(1, "Error Number of Texture\n", 24);
        return (-1);
    }
    if (list->bParsing < 3)
    {
        write(1, "Error in map\n", 13);
        return (-1);
    }
    if (ft_map(list) == -1)
        return (-1);
    return (1);
}
