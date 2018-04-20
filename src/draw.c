/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:52:25 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/14 12:26:57 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_proj(t_fdf *e, t_matrice final, t_cal *res)
{
	res->z = e->tab[res->y][res->x].z * e->moove_z * -1;
	res->tmpx = res->x * final.a + res->y * final.b + res->z * final.c;
	res->tmpy = res->x * final.d + res->y * final.e + res->z * final.f;
	res->tmpz = res->x * final.g + res->y * final.h + res->z * final.i;
	e->tab[res->y][res->x].x = (((res->cte1 * res->tmpx)
		- (res->cte2 * res->tmpy))) * e->zoom;
	e->tab[res->y][res->x].y = ((res->tmpz + ((res->cte1 / 2) * res->tmpx)
		+ ((res->cte2 / 2) * res->tmpy))) * e->zoom;
	e->tab[res->y][res->x].x += e->moove_x;
	e->tab[res->y][res->x].y += e->moove_y;
}

static void		ft_calc_xy(t_fdf *e)
{
	t_cal		res;
	t_matrice	matx;
	t_matrice	maty;
	t_matrice	matz;
	t_matrice	final;

	res.y = 0;
	res.cte1 = 1;
	res.cte2 = 1;
	matx = ft_fill_matx(e);
	maty = ft_fill_maty(e);
	matz = ft_fill_matz(e);
	final = ft_calc_mat(matx, maty);
	final = ft_calc_mat(final, matz);
	while (res.y < e->len_y)
	{
		res.x = 0;
		while (res.x < e->len_x)
		{
			ft_proj(e, final, &res);
			res.x++;
		}
		res.y++;
	}
}

void			draw_line(t_fdf *e)
{
	int x;
	int y;

	y = 0;
	ft_calc_xy(e);
	while (y < e->len_y)
	{
		x = 0;
		while (x < e->len_x - 1)
		{
			e->x0 = e->tab[y][x].x;
			e->x1 = e->tab[y][x + 1].x;
			e->y0 = e->tab[y][x].y;
			e->y1 = e->tab[y][x + 1].y;
			e->color = (e->tab[y][x].z == 0) ? e->tab[y][x + 1].z
				* 25 + 0x00F0FFFF : e->tab[y][x].z * 25 + 0x00F0FFFF;
			line(e);
			x++;
		}
		y++;
	}
}

void			draw_column(t_fdf *e)
{
	int x;
	int y;

	y = 0;
	ft_calc_xy(e);
	while (y < e->len_y - 1)
	{
		x = 0;
		while (x < e->len_x)
		{
			e->x0 = e->tab[y][x].x;
			e->x1 = e->tab[y + 1][x].x;
			e->y0 = e->tab[y][x].y;
			e->y1 = e->tab[y + 1][x].y;
			e->color = (e->tab[y][x].z == 0) ? e->tab[y + 1][x].z
				* 25 + 0x00F0FFFF : e->tab[y][x].z * 25 + 0x00F0FFFF;
			line(e);
			x++;
		}
		y++;
	}
}
