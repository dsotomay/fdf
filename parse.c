/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dysotoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 20:07:57 by dysotoma          #+#    #+#             */
/*   Updated: 2018/04/26 12:52:28 by dysotoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define IMG img->height * img->width

static	int		number_count(char *line)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if ((line[i + 1] == ' ' || !line[i + 1]) &&
		(line[i] >= '0' && line[i] <= '9'))
			count++;
		i++;
	}
	return (count);
}

static	int		get_file(char *file)
{
	int fd;

	if ((fd = open(file, O_RDONLY)) < 0)
		exit(0);
	return (fd);
}

static	int		pre_parse(int *fd)
{
	char	*line;
	int		ret;
	int		height;

	height = 0;
	while ((ret = get_next_line(*fd, &line)) > 0)
		height += ret;
	close(*fd);
	return (height);
}

static	void	split_to_number(t_pos **dest, char *line, int width)
{
	static int	i = 0;
	static int	cx = 0;
	static int	cy = 0;
	int			j;
	char		**split;

	j = 0;
	split = ft_strsplit(line, ' ');
	while (split[j])
	{
		if (cx == width)
		{
			cy++;
			cx = 0;
		}
		(*dest)[i].x = cx;
		(*dest)[i].y = cy;
		(*dest)[i].z = ft_atoi(split[j++]);
		i++;
		cx++;
	}
	ft_strdel(split);
}

t_pos			*parse(t_size *img, char *file)
{
	int			ret;
	char		*line;
	t_pos		*dst;
	int			i;
	int			fd;

	fd = get_file(file);
	img->height = pre_parse(&fd);
	img->width = 0;
	i = 0;
	fd = get_file(file);
	dst = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (img->width == 0)
			img->width = number_count(line);
		if (img->width != number_count(line))
			exit(0);
		if (dst == '\0')
			if (!(dst = (t_pos*)ft_memalloc(sizeof(t_pos) * IMG)))
				return (NULL);
		split_to_number(&dst, line, img->width);
	}
	close(fd);
	return (dst);
}
