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
# define screenWidth 1280
# define screenHeight 720

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
	int			savebmp;
	int			aParsing;
	int			bParsing;
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
	float		movespeed;
	float		rotspeed;
	char		*size;
	char		*textN;
	char		*textS;
	char		*textE;
	char		*textW;
	char		*textSprite;
	char		*textF;
	char		*textC;
	char		*tmpmap;
	char		**map;
}				t_list;

void			ft_raycast(t_list *list);
void			ft_readKeys(t_list *list);
void			ft_calculate_ray_and_deltaDist(t_list *list, int a);
void			ft_calculate_step_and_sideDist(t_list *list);
void			ft_perform_dda(t_list *list);
void			ft_calculate_dist(t_list *list);
void			ft_calculate_height_wall(t_list *list);
void			ft_init_colors(t_list *list);
void			ft_verline(t_list *list, int a);
void			ft_init_list(t_list *list);
void			ft_init_list2(t_list *list);
void			ft_init_list3(t_list *list);
void			ft_whatstheconf(t_list *list, char *line);
void			ft_whatstheconf2(t_list *list, char *line);
void			ft_whatstheconf3(t_list *list, char *line);
int				ft_whatsinmap(t_list *list, char *line);
int				ft_parsing(char *file, t_list *list);
int				ft_checkerror(int argc, char **argv, t_list *list);
//int				ft_check(t_list *list, int fd, char *line);
//int				ft_map(t_list *list, int fd, char *line);
//int			ft_keyboard(int keycode, t_list *list);

#endif