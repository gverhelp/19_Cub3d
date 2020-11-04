#include "../include/cub3d.h"

void    ft_free_win(t_list *list)
{
    if (list->img)
        mlx_destroy_image(list->mlx, list->img);
    if (list->mlx && list->mlx_win)
        mlx_destroy_window(list->mlx, list->mlx_win);
    if (list->mlx)
    {
        free(list->mlx);
        list->mlx = NULL;
    }
}

void    ft_free_map(t_list *list)
{
    int     a;

    a = 0;
    if (list->tmpmap)
    {
        free(list->tmpmap);
        list->tmpmap = NULL;
    }
    if (list->map)
    {
        while (list->map && *list->map && list->map[a])
        {
            free(list->map[a]);
            list->map[a] = NULL;
            a++;
        }
        free(list->map);
        list->map = NULL;
    }
}

void    ft_free_data2(t_list *list)
{
    if (list->textEA)
    {
        free(list->textEA);
        list->textEA = NULL;
    }
    if (list->textF)
    {
        free(list->textF);
        list->textF = NULL;
    }
    if (list->textC)
    {
        free(list->textC);
        list->textC = NULL;
    }
    if (list->textSprite)
    {
        free(list->textSprite);
        list->textSprite = NULL;
    }
}

void    ft_free_data(t_list *list)
{
    if (list->size)
    {
        free(list->size);
        list->size = NULL;
    }
    if (list->textNO)
    {
        free(list->textNO);
        list->textNO = NULL;
    }
    if (list->textSO)
    {
        free(list->textSO);
        list->textSO = NULL;
    }
    if (list->textWE)
    {
        free(list->textWE);
        list->textWE = NULL;
    }
    ft_free_data2(list);
}

int     ft_exit(t_list *list)
{
    ft_free_map(list);
    ft_free_data(list);
    ft_free_win(list);
    exit(0);
    return (-1);
}