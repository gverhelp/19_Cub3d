/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sprites.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:36:27 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 16:54:32 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_nbsprites(t_list *list)
{
	int	a;
	int	b;

	a = 0;
	if (!list->map)
		return (-1);
	while (list->map[a] != 0)
	{
		b = 0;
		while (list->map[a][b] != 0)
		{
			if (list->map[a][b] == '2')
			{
				list->nbsprites += 1;
			}
			b++;
		}
		a++;
	}
	return (0);
}

void	ft_get_sprites(t_list *list)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	c = 0;
	while (list->map[a] != 0)
	{
		b = 0;
		while (list->map[a][b] != 0)
		{
			if (list->map[a][b] == '2')
			{
				list->spritesx[c] = b + 0.5;
				list->spritesy[c] = a + 0.5;
				c++;
			}
			b++;
		}
		a++;
	}
	list->spritesx[c] = '\0';
	list->spritesy[c] = '\0';
}

int		ft_parsingsprites(t_list *list)
{
	if (ft_nbsprites(list) == -1)
		return (-1);
	if (!(list->spritesx = malloc(sizeof(int *) * list->nbsprites + 1)))
		return (-1);
	if (!(list->spritesy = malloc(sizeof(int *) * list->nbsprites + 1)))
		return (-1);
	ft_get_sprites(list);
	return (0);
}
