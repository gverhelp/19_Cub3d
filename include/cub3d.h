/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverhelp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 13:39:55 by gverhelp          #+#    #+#             */
/*   Updated: 2020/11/14 17:06:34 by gverhelp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

typedef	struct	s_list
{
	void		*img;
	void		*mlx;
	void		*mlx_win;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			color_floor;
	int			color_sky;
	int			savebmp;
	int			aparsing;
	int			bparsing;
	int			position;
	int			comptpos;
	int			screenwidth;
	int			screenheight;
	int			r;
	int			g;
	int			b;
	int			longestline;
	double		*zbuffer;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		time;
	double		oldtime;
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	double		movespeed;
	double		rotspeed;
	double		olddirx;
	double		oldplanex;
	char		*size;
	char		*textno;
	char		*textso;
	char		*textea;
	char		*textwe;
	char		*textsprite;
	char		*textf;
	char		*textc;
	char		*tmpmap;
	char		**map;
	int			texx;
	int			texy;
	double		texpos;
	double		step;
	double		wallx;
	void		*imgno;
	int			*addrno;
	void		*imgso;
	int			*addrso;
	void		*imgwe;
	int			*addrwe;
	void		*imgea;
	int			*addrea;
	void		*imgsprite;
	int			*addrsprite;
	int			color;
	int			texheight;
	int			texwidth;
	int			nbsprites;
	double		*spritesx;
	double		*spritesy;
	double		spritedistance;
	double		sprtx;
	double		sprty;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			spritewidth;
	int			drawstarty;
	int			drawstartx;
	int			drawendy;
	int			drawendx;
	int			stripe;
}				t_list;

int				ft_start(t_list *list);
int				ft_raycasting(t_list *list);
void			ft_readkeys(t_list *list);
void			ft_raycast(t_list *list, int a);
void			ft_raycast2(t_list *list);
void			ft_raycast3(t_list *list);
void			ft_raycast4(t_list *list);
void			ft_verline(t_list *list, int a);
void			ft_verline2(t_list *list, int a, int b);
void			ft_init_list(t_list *list);
void			ft_init_list2(t_list *list);
void			ft_init_list3(t_list *list);
void			ft_init_list4(t_list *list);
void			ft_init_list5(t_list *list);
int				ft_whatstheconf(t_list *list, char *line);
int				ft_r_size(t_list *list, char *line);
int				ft_text_no(t_list *list, char *line);
int				ft_text_we(t_list *list, char *line);
int				ft_text_ea(t_list *list, char *line);
int				ft_text_f(t_list *list, char *line);
int				ft_text_c(t_list *list, char *line);
int				ft_text_so(t_list *list, char *line);
int				ft_text_sprite(t_list *list, char *line);
void			ft_dataposition(t_list *list, int a, int b);
void			ft_dataposition2(t_list *list, int a, int b);
void			ft_checkmaxminscreen(t_list *list);
int				ft_whatsinmap(t_list *list, char *line);
int				ft_parsing(char *file, t_list *list);
int				ft_checkerror(int argc, char **argv, t_list *list);
int				ft_check(t_list *list);
int				ft_map(t_list *list);
int				ft_checktxterror(t_list *list);
int				ft_checktxterror2(t_list *list);
int				ft_checkpos(t_list *list);
int				ft_checkerrorpos(t_list *list, int a, int b);
int				ft_checkspace(t_list *list, int a, int b);
int				ft_keyboard(int keycode, t_list *list);
void			ft_keyboard2(int keycode, t_list *list);
void			ft_keyboard3(int keycode, t_list *list);
void			ft_keyboard4(int keycode, t_list *list);
int				ft_esc(t_list *list);
int				ft_visible(t_list *list);
int				ft_checkscreen(t_list *list);
int				ft_checkskyfloor(t_list *list);
int				ft_checkskyfloor2(t_list *list, char *str);
int				ft_checkskyfloor3(t_list *list, char *str, int a);
int				ft_checkskyfloor4(t_list *list, char *str, int a);
int				ft_hexa(t_list *list);
int				ft_checkmap(t_list *list);
int				ft_checkcharacters(t_list *list);
int				ft_isspace(int c);
int				ft_checkfirstline(t_list *list);
int				ft_checklastline(t_list *list);
int				ft_checkfirstcolumn(t_list *list);
int				ft_checklastcolumn(t_list *list);
int				ft_checkifhole(t_list *list);
void			ft_addapace(t_list *list);
void			ft_addspace2(t_list *list, int a);
void			ft_addspace3(t_list *list, int a);
int				ft_checktextures(t_list *list);
int				ft_checktextures2(t_list *list);
void			ft_checktextures3(t_list *list);
int				ft_walltexture(t_list *list);
int				ft_textno(t_list *list);
int				ft_textso(t_list *list);
int				ft_textwe(t_list *list);
int				ft_textea(t_list *list);
int				ft_nbsprites(t_list *list);
int				ft_parsingsprites(t_list *list);
void			ft_get_sprites(t_list *list);
void			ft_raycasting_sprites(t_list *list);
void			ft_calculate_transform(t_list *list, int a);
void			ft_switch_sprites(t_list *list, int a, int b);
void			ft_sort_sprite(t_list *list);
void			ft_calculate_draw_start_end(t_list *list);
void			ft_verline_sprites(t_list *list);
void			ft_write_sprites(t_list *list);
int				ft_bmp(t_list *list);
int				ft_bmp2(t_list *list);
void			ft_create_header(int fd, t_list *list, int file_size);
int				ft_exit(t_list *list);
void			ft_free_data(t_list *list);
void			ft_free_data2(t_list *list);
void			ft_free_map(t_list *list);
void			ft_free_win(t_list *list);

#endif
