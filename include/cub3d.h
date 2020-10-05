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
	int			position;
	int			comptPos;
	int			screenWidth;
	int			screenHeight;
	int			r;
	int			g;
	int			b;
	double		zbuffer;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		time;
	double		oldTime;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	double		movespeed;
	double		rotspeed;
	double		oldDirX;
	double		oldPlaneX;
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

int				ft_raycasting(t_list *list);
void			ft_readKeys(t_list *list);
void			ft_raycast(t_list *list, int a);
void			ft_raycast2(t_list *list, int a);
void			ft_raycast3(t_list *list, int a);
void			ft_raycast4(t_list *list, int a);
void			ft_init_colors(t_list *list);
void			ft_verline(t_list *list, int a);
void			ft_init_list(t_list *list);
void			ft_init_list2(t_list *list);
void			ft_init_list3(t_list *list);
void			ft_whatstheconf(t_list *list, char *line);
void			ft_whatstheconf2(t_list *list, char *line);
void			ft_whatstheconf3(t_list *list, char *line);
void			ft_dataPosition(t_list *list, int a, int b);
void			ft_dataPosition2(t_list *list, int a, int b);
void			ft_checkMaxMinScreen(t_list *list);
int				ft_whatsinmap(t_list *list, char *line);
int				ft_parsing(char *file, t_list *list);
int				ft_checkerror(int argc, char **argv, t_list *list);
int				ft_check(t_list *list);
int				ft_map(t_list *list);
int				ft_checkTxtError(t_list *list);
int				ft_checkpos(t_list *list);
int				ft_checkErrorPos(t_list *list, int a, int b);
int				ft_checkSpace(t_list *list, int a, int b);
int				ft_keyboard(int keycode, t_list *list);
void			ft_keyboard2(int keycode, t_list *list);
void			ft_keyboard3(int keycode, t_list *list);
void			ft_keyboard4(int keycode, t_list *list);
int				ft_esc(t_list *list);
int				ft_checkScreen(t_list *list);
int				ft_checkSkyFloor(t_list *list);
int				ft_checkSkyFloor2(t_list *list, char *str);
int				ft_checkSkyFloor3(t_list *list, char *str, int a);
int				ft_hexa(t_list *list);

#endif