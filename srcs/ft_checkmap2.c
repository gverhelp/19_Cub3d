/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:33:20 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 16:49:41 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_addspace3(t_list *list, int a)
{
	char	*tmp;

	tmp = NULL;
	list->map[a] = ft_strjoin(list->map[a], " ");
	free(tmp);
}

void	ft_addspace(t_list *list)
{
	int	a;
	int	b;
	int	c;

	a = 1;
	c = 0;
	while (list->map && list->map[a])
	{
		if (ft_strlen(list->map[a - 1]) < ft_strlen(list->map[a]))
		{
			b = ft_strlen(list->map[a]) - ft_strlen(list->map[a - 1]);
			while (c < b)
			{
				ft_addspace3(list, a - 1);
				c++;
			}
		}
		ft_addspace2(list, a);
		a++;
	}
}

int		ft_checkfirstcolumn(t_list *list)
{
	int	a;
	int	b;

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

int		ft_checklastcolumn(t_list *list)
{
	int	a;
	int	b;

	a = 0;
	while (list->map && list->map[a])
	{
		b = ft_strlen(list->map[a]) - 1;
		if (list->map[a][b] != '1')
			return (-1);
		a++;
	}
	ft_addspace(list);
	return (0);
}

int		ft_checkifhole(t_list *list)
{
	int	a;
	int	b;

	a = 0;
	while (list->map && list->map[a + 1])
	{
		b = 0;
		while (list->map[a][b])
		{
			if (list->map[a][b] == '0' || list->map[a][b] == '2')
				if (ft_checkspace(list, a, b) == -1)
					return (-1);
			b++;
		}
		a++;
	}
	return (0);
}
