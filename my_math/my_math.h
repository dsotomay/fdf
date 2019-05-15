/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 20:02:49 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/21 20:02:54 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MATH_H
# define MY_MATH_H

# include <math.h>
# define IDENTITY (t_matrix){1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}

typedef struct	s_matrix
{
	float arr[16];
}				t_matrix;

typedef struct	s_size
{
	int	height;
	int	width;
	int	bpp;
	int	sizeline;
	int	endian;
}				t_size;

typedef struct	s_pos
{
	float	x;
	float	y;
	float	z;
	float	w;
}				t_pos;

typedef	struct	s_vertex
{
	t_pos	*Local;
	t_pos	*World;
	t_pos	*Aligned;
}				t_vertex;

typedef	struct	s_fdf
{
	void	*window;
	void	*mlx;
	void	*image;
}				t_fdf;

t_matrix	*mat_mult(t_matrix *mat1, t_matrix *mat2);
t_matrix	*trans(t_matrix *matrix, t_pos *s_mat, t_pos *t_mat, t_pos *r);
void		vec_mat_mult(t_pos *src, t_matrix *mat, t_pos *dest);
void		mat_trans(t_pos *t, t_matrix *tmat);
void		scale(t_pos *s, t_matrix *smat);
void		rotate_x(float x, t_matrix *xmat);
void		rotate_y(float y, t_matrix *ymat);
void		rotate_z(float z, t_matrix *zmat);

#endif
