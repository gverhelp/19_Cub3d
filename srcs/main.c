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

int		ft_checkerror(int argc, char **argv, t_list *list)
{
	if (argc >= 2)
	{
		if ((!(ft_strrchr(argv[1], '.'))) || (ft_strncmp(ft_strrchr(argv[1], '.'), ".cub\0", 5)))
		{
			write(1, "Error\nError not .cub\n", 21);
			return (-1);
		}
	}
	if (argc != 2)
	{
		if ((argc == 3) && (!(ft_strncmp(argv[2], "--save\0", 7))))
				list->savebmp = 1;
		else
		{
			write(1, "Error\nError In The Arguments\n", 29);
			return (-1);
		}
	}
	if (ft_parsing(argv[1], list) == -1)
	{
		write(1, "Error in the parsing\n", 21);
		return (-1);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_list	list;

	ft_init_list(&list);
	if (ft_checkerror(argc, argv, &list) == -1)
		return (-1);
	list.mlx_win = mlx_new_window(list.mlx, list.screenWidth, list.screenHeight, "Cub3d");
	list.img = mlx_new_image(list.mlx, list.screenWidth, list.screenHeight);
	list.addr = (int*)mlx_get_data_addr(list.img, &list.bits_per_pixel, &list.line_length, &list.endian);
	ft_raycasting(&list);
	ft_readKeys(&list);
	mlx_loop(list.mlx);
	return (0);
}
