/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:31:40 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 19:35:46 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\r' ||
		c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_checklastline(t_list *list)
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

int	ft_checkfirstline(t_list *list)
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

int	ft_checkcharacters(t_list *list)
{
	int a;
	int b;

	a = 0;
	while (list->map && list->map[a])
	{
		b = 0;
		while (list->map[a][b] != '\0')
		{
			if (list->map[a][b] != '0' && list->map[a][b] != '1'
					&& list->map[a][b] != '2' &&
					(ft_isspace(list->map[a][b]) == 0))
				return (-1);
			b++;
		}
		a++;
	}
	return (0);
}

int	ft_checkmap(t_list *list)
{
	if (ft_checkcharacters(list) == -1)
		return (-1);
	if (ft_checkfirstline(list) == -1)
		return (-1);
	if (ft_checklastline(list) == -1)
		return (-1);
	if (ft_checkfirstcolumn(list) == -1)
		return (-1);
	if (ft_checklastcolumn(list) == -1)
		return (-1);
	if (ft_checkifhole(list) == -1)
		return (-1);
	return (0);
}
