/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:57:41 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 14:47:13 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				red_cross(int key)
{
	key = (int)key;
	exit(0);
	return (0);
}

int				expose_hook(t_fdf *aff)
{
	ft_bzero(aff->img_str, WIN_Y * aff->s_l);
	draw_column(aff);
	draw_line(aff);
	mlx_put_image_to_window(aff->img_str, aff->win, aff->img, 0, 0);
	return (0);
}

static void		ft_moove(int keycode, t_fdf *aff)
{
	if (keycode == 126)
		aff->moove_y -= 10;
	if (keycode == 125)
		aff->moove_y += 10;
	if (keycode == 124)
		aff->moove_x += 10;
	if (keycode == 123)
		aff->moove_x -= 10;
}

static void		ft_zoom(int keycode, t_fdf *aff)
{
	if (keycode == 75)
		aff->moove_z -= 0.1;
	if (keycode == 67)
		aff->moove_z += 0.1;
	if (keycode == 69)
		aff->zoom += 1;
	if (keycode == 78)
		aff->zoom -= (aff->zoom > 0) ? 1 : 0;
}

int				key_hook(int keycode, t_fdf *aff)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 126 || keycode == 125 || keycode == 123 || keycode == 124)
		ft_moove(keycode, aff);
	if (keycode == 75 || keycode == 67 || keycode == 69 || keycode == 78)
		ft_zoom(keycode, aff);
	if (keycode == 12)
		aff->rotx += 0.1;
	if (keycode == 14)
		aff->rotx -= 0.1;
	if (keycode == 0)
		aff->roty += 0.1;
	if (keycode == 2)
		aff->roty -= 0.1;
	if (keycode == 6)
		aff->rotz += 0.1;
	if (keycode == 8)
		aff->rotz -= 0.1;
	if (keycode == 71)
		init_struct(aff);
	expose_hook(aff);
	return (0);
}
