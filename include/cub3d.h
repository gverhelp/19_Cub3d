/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:55 by gverhelp          #+#    #+#             */
/*   Updated: 2020/09/09 18:30:46 by gverhelp         ###   ########.fr       */
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

typedef struct	s_list
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
	int			color_floor;
	int			color_sky;
	int			color_wall_w;
	int			color_wall_e;
	int			color_wall_s;
	int			color_wall_n;
	float		posX;
	float		posY;
	float		dirX;
	float		dirY;
	float		planeX;
	float		planeY;
	float		time;
	float		oldTime;
	float		cameraX;
	float		rayDirX;
	float		rayDirY;
	float		sideDistX;
	float		sideDistY;
	float		deltaDistX;
	float		deltaDistY;
	float		perpWallDist;
}				t_list;

typedef struct	s_list2
{
	char		*size;
	char		*textN;
	char		*textS;
	char		*textE;
	char		*textW;
	char		*textSprite;
	char		*textF;
	char		*textC;
}				t_list2;

void			ft_raycast(t_list *list);
void			ft_readKeys(t_list *list, char **argv);
void			ft_calculate_ray_and_deltaDist(t_list *list, int a);
void			ft_calculate_step_and_sideDist(t_list *list);
void			ft_perform_dda(t_list *list);
void			ft_calculate_dist(t_list *list);
void			ft_calculate_height_wall(t_list *list);
void			ft_init_colors(t_list *list);
void			ft_verline(t_list *list, int a);
void			ft_init_list(t_list *list);
void			ft_init_list2(t_list *list);
void			ft_init_list_parsing(t_list2 *list2);
void			ft_whatstheconf(t_list2 *list2, char *line);
void			ft_whatstheconf2(t_list2 *list2, char *line);
void			ft_whatstheconf3(t_list2 *list2, char *line);
int				ft_parsing(char *file);

#endif