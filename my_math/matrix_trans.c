/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_trans.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 13:54:04 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/23 13:54:07 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"

void	mat_trans(t_pos *t, t_matrix *tmat)
{
	tmat->arr[0] = 1;
	tmat->arr[1] = 0;
	tmat->arr[2] = 0;
	tmat->arr[3] = 0;
	tmat->arr[4] = 0;
	tmat->arr[5] = 1;
	tmat->arr[6] = 0;
	tmat->arr[7] = 0;
	tmat->arr[8] = 0;
	tmat->arr[9] = 0;
	tmat->arr[10] = 1;
	tmat->arr[11] = 0;
	tmat->arr[12] = t->x;
	tmat->arr[13] = t->y;
	tmat->arr[14] = t->z;
	tmat->arr[15] = 1;
}
// #define ZERO_POS (t_pos){0, 0, 0, 0}

// t_matrix m = rotation(scaling, ZERO_POS, ZERO_POS);

// t_matrix m = rotation(scaling, transform, rotation);

// t_matrix rotation;
// t_matrix scale;
// t_matrix transform;

// output = translate_matrix * scale_matrix * rotation_matrix

// t_matrix	transform(t_pos s, t_pos t, t_pos r)
// {
// 	t_matrix ret;

// 	ret.arr[0] = (cos(r->y) * cos(r->z)) + s->x;
// 	ret.arr[1] = sin(r->z);
// 	ret.arr[2] = -sin(r->y);
// 	ret.arr[3] = 0;
// 	ret.arr[4] = -sin(r->z);
// 	ret.arr[5] = (cos(r->x) * cos(r->z)) + s->y;
// 	ret.arr[6] = sin(r->x);
// 	ret.arr[7] = 0;
// 	ret.arr[8] = sin(r->y);
// 	ret.arr[9] = -sin(r->x);
// 	ret.arr[10] = (cos(r->x) * cos(r->y)) + s->z;
// 	ret.arr[11] = 0;
// 	ret.arr[12] = t->x;
// 	ret.arr[13] = t->y;
// 	ret.arr[14] = t->z;
// 	ret.arr[15] = 1;
// 	return (ret);
// }

void	scale(t_pos *s, t_matrix *smat)
{
	smat->arr[0] = s->x;
	smat->arr[1] = 0;
	smat->arr[2] = 0;
	smat->arr[3] = 0;
	smat->arr[4] = 0;
	smat->arr[5] = s->y;
	smat->arr[6] = 0;
	smat->arr[7] = 0;
	smat->arr[8] = 0;
	smat->arr[9] = 0;
	smat->arr[10] = s->z;
	smat->arr[11] = 0;
	smat->arr[12] = 0;
	smat->arr[13] = 0;
	smat->arr[14] = 0;
	smat->arr[15] = 1;
}

void	rotate_x(float x, t_matrix *xmat)
{
	xmat->arr[0] = 1;
	xmat->arr[1] = 0;
	xmat->arr[2] = 0;
	xmat->arr[3] = 0;
	xmat->arr[4] = 0;
	xmat->arr[5] = cos(x);
	xmat->arr[6] = sin(x);
	xmat->arr[7] = 0;
	xmat->arr[8] = 0;
	xmat->arr[9] = -sin(x);
	xmat->arr[10] = cos(x);
	xmat->arr[11] = 0;
	xmat->arr[12] = 0;
	xmat->arr[13] = 0;
	xmat->arr[14] = 0;
	xmat->arr[15] = 1;
}

void	rotate_y(float y, t_matrix *ymat)
{
	ymat->arr[0] = cos(y);
	ymat->arr[1] = 0;
	ymat->arr[2] = -sin(y);
	ymat->arr[3] = 0;
	ymat->arr[4] = 0;
	ymat->arr[5] = 1;
	ymat->arr[6] = 0;
	ymat->arr[7] = 0;
	ymat->arr[8] = sin(y);
	ymat->arr[9] = 0;
	ymat->arr[10] = cos(y);
	ymat->arr[11] = 0;
	ymat->arr[12] = 0;
	ymat->arr[13] = 0;
	ymat->arr[14] = 0;
	ymat->arr[15] = 1;
}

void	rotate_z(float z, t_matrix *zmat)
{
	zmat->arr[0] = cos(z);
	zmat->arr[1] = sin(z);
	zmat->arr[2] = 0;
	zmat->arr[3] = 0;
	zmat->arr[4] = -sin(z);
	zmat->arr[5] = cos(z);
	zmat->arr[6] = 0;
	zmat->arr[7] = 0;
	zmat->arr[8] = 0;
	zmat->arr[9] = 0;
	zmat->arr[10] = 1;
	zmat->arr[11] = 0;
	zmat->arr[12] = 0;
	zmat->arr[13] = 0;
	zmat->arr[14] = 0;
	zmat->arr[15] = 1;
}
