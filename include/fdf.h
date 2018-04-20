/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:14:53 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/14 12:28:50 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"
# define SUCCES		0
# define FAILED		1
# define WIN_X		1900
# define WIN_Y		1100
# define ZOOM		15

typedef struct		s_dot
{
	int		x;
	int		y;
	int		z;
}					t_dot;

typedef struct		s_matrice
{
	float a;
	float b;
	float c;
	float d;
	float e;
	float f;
	float g;
	float h;
	float i;
}					t_matrice;

typedef struct		s_fdf
{
	char	*img_str;
	int		*img_int;
	void	*mlx;
	void	*win;
	void	*img;
	t_dot	**tab;
	int		bpp;
	int		s_l;
	int		endian;
	int		map_x;
	int		map_y;
	int		len_x;
	int		len_y;
	int		zoom;
	int		moove_y;
	int		moove_x;
	float	moove_z;
	float	rotx;
	float	roty;
	float	rotz;
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	long	color;
}					t_fdf;

typedef struct		s_cal
{
	float	cte1;
	float	cte2;
	float	tmpx;
	float	tmpy;
	float	tmpz;
	int		x;
	int		y;
	float	z;
}					t_cal;

typedef struct		s_bres
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		e2;
	int		err;
}					t_bres;

void				line(t_fdf *e);
void				init_struct(t_fdf *res);
void				draw_line(t_fdf *e);
void				draw_column(t_fdf *e);
int					red_cross(int key);
int					expose_hook(t_fdf *aff);
int					key_hook(int keycode, t_fdf *aff);
t_dot				**ft_parse_tab(t_fdf *af, char **av);
t_matrice			ft_fill_matx(t_fdf *e);
t_matrice			ft_fill_maty(t_fdf *e);
t_matrice			ft_fill_matz(t_fdf *e);
t_matrice			ft_calc_mat(t_matrice mat1, t_matrice mat2);

#endif
