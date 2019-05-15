/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_mult.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 11:14:22 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/24 16:05:25 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"
#define XYZ t_matrix *xmat; t_matrix *ymat; t_matrix *zmat

t_matrix	*mat_mult(t_matrix *mat1, t_matrix *mat2)
{
	int i;
	int j;
	t_matrix *dest;

	i = 0;
	dest = 0;
	while (i < 16)
	{
		j = 0;
		while (j < 4)
		{
			dest->arr[i + j] =  mat1->arr[i + 0] * mat2->arr[0 + j]+
								mat1->arr[i + 1] * mat2->arr[4 + j]+
								mat1->arr[i + 2] * mat2->arr[8 + j]+
								mat1->arr[i + 3] * mat2->arr[12 + j];
			j++;
		}
		i += 4;
	}
	return (dest);
}

void	vec_mat_mult(t_pos *src, t_matrix *mat, t_pos *dest)
{
	dest->x = src->x * mat->arr[0]+
				src->y * mat->arr[4]+
				src->z * mat->arr[8]+
						 mat->arr[12];
	dest->y = src->x * mat->arr[1]+
				src->y * mat->arr[5]+
				src->z * mat->arr[9]+
						 mat->arr[13];
	dest->z = src->x * mat->arr[2]+
				src->y * mat->arr[6]+
				src->z * mat->arr[10]+
						 mat->arr[14];
}

// t_matrix	*trans(t_matrix *matrix, t_pos *s_mat, t_pos *t_mat, t_pos *r)
// {
// 	t_matrix *smat;
// 	t_matrix *tmat;
// 	t_matrix *rmat;

// 	XYZ;
// 	rotate_x(r->x, xmat);
// 	rotate_y(r->y, ymat);
// 	rotate_z(r->z, zmat);
// 	scale(s_mat, smat);
// 	mat_trans(t_mat, tmat);
// 	if (matrix == 0)
// 		matrix = IDENTITY;
// 	// mat_mult(mat_mult(matrix, ymat);, xmat, mat2);
// 	rmat = mat_mult(mat_mult(mat_mult(matrix, ymat), xmat), zmat);
// 	return (mat_mult(mat_mult(rmat, smat), tmat));
// }
