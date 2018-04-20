/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:46:08 by ctourret          #+#    #+#             */
/*   Updated: 2017/04/13 14:47:54 by ctourret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_matrice	ft_fill_matx(t_fdf *e)
{
	t_matrice ret;

	ret.a = 1;
	ret.b = 0;
	ret.c = 0;
	ret.d = 0;
	ret.e = cos(e->rotx);
	ret.f = -sin(e->rotx);
	ret.g = 0;
	ret.h = sin(e->rotx);
	ret.i = cos(e->rotx);
	return (ret);
}

t_matrice	ft_fill_maty(t_fdf *e)
{
	t_matrice ret;

	ret.a = cos(e->roty);
	ret.b = 0;
	ret.c = sin(e->roty);
	ret.d = 0;
	ret.e = 1;
	ret.f = 0;
	ret.g = -sin(e->roty);
	ret.h = 0;
	ret.i = cos(e->roty);
	return (ret);
}

t_matrice	ft_fill_matz(t_fdf *e)
{
	t_matrice ret;

	ret.a = cos(e->rotz);
	ret.b = -sin(e->rotz);
	ret.c = 0;
	ret.d = sin(e->rotz);
	ret.e = cos(e->rotz);
	ret.f = 0;
	ret.g = 0;
	ret.h = 0;
	ret.i = 1;
	return (ret);
}

t_matrice	ft_calc_mat(t_matrice mat1, t_matrice mat2)
{
	t_matrice res;

	res.a = (mat1.a * mat2.a) + (mat1.b * mat2.d) + (mat1.c * mat2.g);
	res.b = (mat1.a * mat2.b) + (mat1.b * mat2.e) + (mat1.c * mat2.h);
	res.c = (mat1.a * mat2.c) + (mat1.b * mat2.f) + (mat1.c * mat2.i);
	res.d = (mat1.d * mat2.a) + (mat1.e * mat2.d) + (mat1.f * mat2.g);
	res.e = (mat1.d * mat2.b) + (mat1.e * mat2.e) + (mat1.f * mat2.h);
	res.f = (mat1.d * mat2.c) + (mat1.e * mat2.f) + (mat1.f * mat2.i);
	res.g = (mat1.g * mat2.a) + (mat1.h * mat2.d) + (mat1.i * mat2.g);
	res.h = (mat1.g * mat2.b) + (mat1.h * mat2.e) + (mat1.i * mat2.h);
	res.i = (mat1.g * mat2.c) + (mat1.h * mat2.f) + (mat1.i * mat2.i);
	return (res);
}
