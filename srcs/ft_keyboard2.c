/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:42 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 20:38:13 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_visible(t_list *list)
{
	if (ft_raycasting(list) == -1)
	{
		write(1, "Error\nError raycasting (visi)\n", 30);
		return (-1);
	}
	return (0);
}

int	ft_esc(t_list *list)
{
	(void)list;
	exit(0);
	return (0);
}
