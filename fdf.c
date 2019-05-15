/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:05:04 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/17 18:05:08 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	quit(int kc)
{
	if (kc == 53)
		exit(1);
	return (0);
}

int			main(int ac, char **av)
{
	t_size		img;
	t_vertex	map;
	t_fdf		fdf;

	if (ac != 2)
	{
		ft_putendl("Usage: [text.fdf]");
		return (0);
	}
	fdf.mlx = mlx_init();
	fdf.window = mlx_new_window(fdf.mlx, W_WIDTH, W_HEIGHT, "FDF");
	map.Local = parse(&img, av[1]);
	render(fdf, img, map);
	mlx_key_hook(fdf.window, quit, fdf.window);
	mlx_loop(fdf.mlx);
}
