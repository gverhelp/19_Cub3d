/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.ff>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:33:33 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/11 19:40:07 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_addspace2(t_list *list, int a)
{
	int	b;
	int	c;

	if (ft_strlen(list->map[a - 1]) > ft_strlen(list->map[a]))
	{
		b = ft_strlen(list->map[a - 1]) - ft_strlen(list->map[a]);
		c = 0;
		while (c < b)
		{
			ft_addspace3(list, a);
			c++;
		}
	}
}
