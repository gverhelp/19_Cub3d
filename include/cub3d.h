/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:55 by gverhelp          #+#    #+#             */
/*   Updated: 2020/03/12 12:46:55 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define mapWidth 24
# define mapHeight 24
# define screenWidth 1920
# define screenHeight 1080

typedef struct s_data
{
	void	*img;
	void	*mlx;
	void	*mlx_win;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mapX;
	int		mapY;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		color_floor;
	int		color_sky;
	int		color_wall_w;
	int		color_wall_e;
	int		color_wall_s;
	int		color_wall_n;
	float	posX;
	float	posY;
	float	dirX;
	float	dirY;
	float	planeX;
	float	planeY;
	float	time;
	float	oldTime;
	float	cameraX;
	float	rayDirX;
	float	rayDirY;
	float	sideDistX;
	float	sideDistY;
	float	deltaDistX;
	float	deltaDistY;
	float	perpWallDist;
}			t_data;

void	ft_start(t_data *data);
void	ft_readKeys(t_data *data, char **argv);
void	ft_calculate_ray_and_deltaDist(t_data *data, int a);
void	ft_calculate_step_and_sideDist(t_data *data);
void	ft_perform_dda(t_data *data);
void	ft_calculate_dist(t_data *data);
void	ft_calculate_height_wall(t_data *data);
void	ft_init_colors(t_data *data);
void	ft_verline(t_data *data, int a);
void	ft_init_list(t_data *data);
void	ft_init_list_2(t_data *data);

#endif
