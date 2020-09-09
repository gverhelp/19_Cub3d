/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:04:49 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/09 18:59:20 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_raycast(t_list *list)
{
	int	a;

	a = 0;
	ft_init_colors(list);
	while (a < screenWidth)
	{
		list->hit = 0; //what direction to stop in x or y-drection (either +1 or -1)
		ft_calculate_ray_and_deltaDist(list, a);
		ft_calculate_step_and_sideDist(list);
		ft_perform_dda(list);
		ft_calculate_dist(list);
		ft_calculate_height_wall(list);
		ft_verline(list, a);
		a++;
	}
}

int		main(int argc, char **argv)
{
	t_list	list;

	argc = argc - 1 + 1;
	ft_init_list(&list);
	ft_init_list2(&list);
	ft_parsing(argv[1]);
///	ft_readKeys(&list, );
	list.mlx = mlx_init();
	list.mlx_win = mlx_new_window(list.mlx, screenWidth, screenHeight, "Mon super carre!");
	list.img = mlx_new_image(list.mlx, screenWidth, screenHeight);
	list.addr = (int*)mlx_get_data_addr(list.img, &list.bits_per_pixel, &list.line_length, &list.endian);
	ft_raycast(&list);
	mlx_put_image_to_window(list.mlx, list.mlx_win, list.img, 0, 0);
	mlx_loop(list.mlx);
	return (0);
}