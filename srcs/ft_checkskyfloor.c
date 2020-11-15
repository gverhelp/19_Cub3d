/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkskyfloor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:34:05 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 19:45:30 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_checkskyfloor4(t_list *list, char *str, int a)
{
	while (ft_isdigit(str[a]))
		a++;
	while (str[a] == ' ')
		a++;
	if (str[a] == ',')
		a++;
	while (str[a] == ' ')
		a++;
	if ((!ft_isdigit(str[a])) ||
			((str[a] == '0' && ft_isdigit(str[a + 1]))))
		return (-1);
	list->b = ft_atoi(&str[a]);
	while (ft_isdigit(str[a]))
		a++;
	if (str[a] != '\0')
		return (-1);
	if (list->r < 0 || list->r > 255 || list->g < 0 ||
			list->g > 255 || list->b < 0 || list->b > 255)
		return (-1);
	return (0);
}

int	ft_checkskyfloor3(t_list *list, char *str, int a)
{
	if ((!ft_isdigit(str[a])) ||
		((str[a] == '0' && ft_isdigit(str[a + 1]))))
		return (-1);
	list->g = ft_atoi(&str[a]);
	if (ft_checkskyfloor4(list, str, a) == -1)
		return (-1);
	return (0);
}

int	ft_checkskyfloor2(t_list *list, char *str)
{
	int a;

	a = 1;
	if (ft_strchr(str, '-'))
		return (-1);
	while (str[a] == ' ')
		a++;
	if ((!ft_isdigit(str[a])) ||
			((str[a] == '0' && ft_isdigit(str[a + 1]))))
		return (-1);
	list->r = ft_atoi(&str[a]);
	while (ft_isdigit(str[a]))
		a++;
	while (str[a] == ' ')
		a++;
	if (str[a] == ',')
		a++;
	while (str[a] == ' ')
		a++;
	if (ft_checkskyfloor3(list, str, a) == -1)
		return (-1);
	return (0);
}

int	ft_hexa(t_list *list)
{
	return (list->r << 16 | list->g << 8 | list->b);
}

int	ft_checkskyfloor(t_list *list)
{
	if (ft_checkskyfloor2(list, list->textf) == -1)
		return (-1);
	list->color_floor = ft_hexa(list);
	if (ft_checkskyfloor2(list, list->textc) == -1)
		return (-1);
	list->color_sky = ft_hexa(list);
	return (0);
}
