/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:06:02 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/17 18:06:05 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "my_math/my_math.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include "minilibx/keys.h"
# define W_WIDTH 1920
# define W_HEIGHT 1080

t_pos	*parse(t_size *img, char *file);
void	render(t_fdf fdf, t_size img, t_vertex map);
void	draw_line(t_pos map0, t_pos map1, t_fdf fdf);
void	clever_put_pixel(t_fdf fdf, int x, int y, int col);
//typedef struct

#endif
