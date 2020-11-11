/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkscreen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:33:50 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 19:43:55 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_checkmaxminscreen(t_list *list)
{
	if (list->screenwidth > 1680)
		list->screenwidth = 1680;
	//    if (list->screenwidth < 720)
	//        list->screenwidth = 720;
	if (list->screenheight > 1050)
		list->screenheight = 1050;
	//    if (list->screenheight < 480)
	//       list->screenheight = 480;
}

int	ft_checkscreen(t_list *list)
{
	int a;

	a = 1;
	while (list->size[a] == ' ')
		a++;
	if (!ft_isdigit(list->size[a]) || list->size[a] == '0')
		return (-1);
	list->screenwidth = ft_atoi(&list->size[a]);
	while (ft_isdigit(list->size[a]))
		a++;
	while (list->size[a] == ' ')
		a++;
	if (!ft_isdigit(list->size[a]) || list->size[a] == '0')
		return (-1);
	list->screenheight = ft_atoi(&list->size[a]);
	while (ft_isdigit(list->size[a]))
		a++;
	if (list->size[a] != '\0')
		return (-1);
	if (list->screenwidth <= 0 || list->screenheight <= 0)
		return (-1);
	ft_checkmaxminscreen(list);
	return (0);
}
