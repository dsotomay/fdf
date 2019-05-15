/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:55:51 by dysotoma          #+#    #+#             */
/*   Updated: 2018/05/04 18:55:55 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define INIT int i; int j

static	t_pos	*set_points(t_size img, t_vertex map)
{
	int i;

	i = 0;
	while (i < img.width * img.height)
	{
		map.Local[i].x -= (img.width / 2);
		map.Local[i].y -= (img.height / 2);
		map.Local[i].x *= ((W_WIDTH / img.width) * 15);
		map.Local[i].y *= ((W_HEIGHT / img.height) * 10);
		map.Local[i].x = (map.Local[i].x - map.Local[i].y) / 30;
		map.Local[i].y = (map.Local[i].x - map.Local[i].y) / -15;
		map.Local[i].z = (map.Local[i].z * 10) / 2;
		map.Local[i].y -= map.Local[i].z;
		i++;
	}
	return (map.Local);
}

void			clever_put_pixel(t_fdf fdf, int x, int y, int col)
{
	mlx_pixel_put(fdf.mlx,
		fdf.window,
		x + (W_WIDTH / 2),
		y + (W_HEIGHT / 2),
		col);
}

void			render(t_fdf fdf, t_size img, t_vertex map)
{
	INIT;
	map.Local = set_points(img, map);
	i = 0;
	while (i < img.height)
	{
		j = 0;
		while (j < img.width)
		{
			if (j < img.width - 1)
			{
				draw_line(map.Local[j + i * img.width],
				map.Local[(j + 1) + i * img.width],
				fdf);
			}
			if (i < img.height - 1)
			{
				draw_line(map.Local[j + i * img.width],
				map.Local[j + (i + 1) * img.width],
				fdf);
			}
			j++;
		}
		i++;
	}
}
