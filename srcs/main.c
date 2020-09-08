/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:04:49 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/08 18:20:58 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_raycast(t_data *data)
{
	int	a;

	a = 0;
	ft_init_colors(data);
	while (a < screenWidth)
	{
		data->hit = 0; //what direction to stop in x or y-drection (either +1 or -1)
		ft_calculate_ray_and_deltaDist(data, a);
		ft_calculate_step_and_sideDist(data);
		ft_perform_dda(data);
		ft_calculate_dist(data);
		ft_calculate_height_wall(data);
		ft_verline(data, a);
		a++;
	}
}

int		main(int argc, char **argv)
{
	t_data	data;

	argc = argc - 1 + 1;
	ft_init_list(&data);
	ft_init_list2(&data);
	ft_parsing(argv[1]);
//	ft_readKeys(&data, );
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, screenWidth, screenHeight, "Mon super carre!");
	data.img = mlx_new_image(data.mlx, screenWidth, screenHeight);
	data.addr = (int*)mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	ft_raycast(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop(data.mlx);
	return (0);
}
