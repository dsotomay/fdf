/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 18:49:15 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/25 18:49:18 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define INIT int i

void	draw_line(t_pos map0, t_pos map1, t_fdf fdf)
{
	float dist;
	float xunit;
	float yunit;
	float px;
	float py;

	INIT;
	dist = sqrt((map0.x - map1.x) * (map0.x - map1.x) +
				(map0.y - map1.y) * (map0.y - map1.y));
	xunit = (map1.x - map0.x) / dist;
	yunit = (map1.y - map0.y) / dist;
	i = 0;
	while (i < (int)(dist + 0.5))
	{
		px = map0.x + i * xunit;
		py = map0.y + i * yunit;
		clever_put_pixel(fdf, px + 0.5, py + 0.5, 0xffffff);
		i++;
	}
}
