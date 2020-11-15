/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:38:01 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 16:49:10 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_create_header(int fd, t_list *list, int file_size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(list->screenwidth);
	header[19] = (unsigned char)(list->screenwidth >> 8);
	header[20] = (unsigned char)(list->screenwidth >> 16);
	header[21] = (unsigned char)(list->screenwidth >> 24);
	header[22] = (unsigned char)((-1) * list->screenheight);
	header[23] = (unsigned char)((-1) * list->screenheight >> 8);
	header[24] = (unsigned char)((-1) * list->screenheight >> 16);
	header[25] = (unsigned char)((-1) * list->screenheight >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

int		ft_bmp2(t_list *list)
{
	int	fd;
	int	file_size;

	fd = open("./screenshot.bmp", O_WRONLY | O_CREAT
		| O_TRUNC | O_APPEND, S_IRWXU);
	if (fd < 0)
	{
		write(1, "Error\nScreenshot did not work\n", 30);
		return (-1);
	}
	file_size = 54 + (list->screenwidth * list->screenheight) * 4;
	ft_create_header(fd, list, file_size);
	write(fd, (char *)list->addr,
		(list->screenwidth * list->screenheight * 4));
	close(fd);
	return (0);
}

int		ft_bmp(t_list *list)
{
	if (ft_bmp2(list) == -1)
	{
		write(1, "Error\nScreenshot did not work\n", 30);
		return (-1);
	}
	else
		list->savebmp = 0;
	exit(1);
	return (0);
}
