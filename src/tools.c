/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:03:08 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 14:54:03 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_pixel_put(t_fdf *aff, int x, int y, int color)
{
	int	res;

	res = (y * WIN_X) + x;
	if ((y > 0 && y < WIN_Y) && (x > 0 && x < WIN_X))
		aff->img_int[res] = color;
}

void			line(t_fdf *e)
{
	t_bres	bres;

	bres.dx = abs(e->x1 - e->x0);
	bres.dy = abs(e->y1 - e->y0);
	bres.sx = e->x0 < e->x1 ? 1 : -1;
	bres.sy = e->y0 < e->y1 ? 1 : -1;
	bres.err = (bres.dx > bres.dy ? bres.dx : -(bres.dy)) / 2;
	bres.e2 = 0;
	while (1)
	{
		ft_pixel_put(e, e->x0, e->y0, (e->color));
		if (e->x0 == e->x1 && e->y0 == e->y1)
			break ;
		bres.e2 = bres.err;
		if (bres.e2 > -(bres.dx))
		{
			bres.err -= bres.dy;
			e->x0 += bres.sx;
		}
		if (bres.e2 < bres.dy)
		{
			bres.err += bres.dx;
			e->y0 += bres.sy;
		}
	}
}

static int		check_ext(char *av)
{
	int		i;
	char	*str;

	str = ".fdf";
	i = 0;
	while (av[i])
	{
		if (av[i] == '.')
		{
			if ((ft_strcmp(str, &av[i])) == 0)
				return (1);
		}
		i++;
	}
	return (0);
}

void			init_struct(t_fdf *res)
{
	res->zoom = 20;
	res->moove_x = WIN_X / 2;
	res->moove_y = WIN_Y / 2;
	res->moove_z = 0.1;
	res->rotx = 0;
	res->roty = 0;
	res->rotz = 0;
}

int				main(int ac, char **av)
{
	t_fdf	*aff;

	if (!(aff = (t_fdf *)malloc(sizeof(t_fdf))))
		return (-1);
	if (ac != 2 || check_ext(av[1]) == 0)
	{
		ft_putendl("Usage : ./fdf file_name.fdf");
		return (-1);
	}
	init_struct(aff);
	aff->tab = ft_parse_tab(aff, av);
	aff->mlx = mlx_init();
	aff->win = mlx_new_window(aff->mlx, WIN_X, WIN_Y, "FDF");
	aff->img = mlx_new_image(aff->mlx, WIN_X, WIN_Y);
	aff->img_str = mlx_get_data_addr(aff->img, &(aff->bpp),
			&(aff->s_l), &(aff->endian));
	mlx_put_image_to_window(aff->img_str, aff->win, aff->img, 0, 0);
	mlx_hook(aff->win, 2, 3, key_hook, aff);
	aff->img_int = (int*)aff->img_str;
	mlx_expose_hook(aff->win, expose_hook, aff);
	mlx_hook(aff->win, 17, (1L << 17), red_cross, aff);
	mlx_loop(aff->mlx);
}
