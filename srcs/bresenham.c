/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:37:14 by achansar          #+#    #+#             */
/*   Updated: 2022/12/21 14:31:13 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	b_left(t_img *img, t_line line, int ex, int ey)
{
	int	dx;
	int	dy;
	int	dist;

	dx = 2 * ex;
	dy = 2 * ey;
	dist = ey;
	line.i = 0;
	while (line.i < dist)
	{
		line.i++;
		img_pix_put(img, line.x0, line.y0, line.color);
		line.y0 += line.iy;
		ey -= dx;
		if (ey < 0)
		{
			ey += dy;
			line.x0 += line.ix;
		}
	}
	return (0);
}

static int	b_right(t_img *img, t_line line, int ex, int ey)
{
	int	dx;
	int	dy;
	int	dist;

	dx = 2 * ex;
	dy = 2 * ey;
	dist = ex;
	line.i = 0;
	while (line.i < dist)
	{
		line.i++;
		img_pix_put(img, line.x0, line.y0, line.color);
		line.x0 += line.ix;
		ex -= dy;
		if (ex < 0)
		{
			ex += dx;
			line.y0 += line.iy;
		}
	}
	return (0);
}

static int	bresenham(t_img *img, t_line line)
{
	int	ex;
	int	ey;

	ex = abs(line.x1 - line.x0);
	ey = abs(line.y1 - line.y0);
	if (line.x0 > line.x1)
		line.ix = -1;
	if (line.y0 > line.y1)
		line.iy = -1;
	if (ex >= ey)
		b_right(img, line, ex, ey);
	if (ex < ey)
		b_left(img, line, ex, ey);
	return (0);
}

int	bresenham_init(t_img *img, t_dot a, t_dot b)
{
	t_line	line;

	line.x0 = a.x;
	line.y0 = a.y;
	line.x1 = b.x;
	line.y1 = b.y;
	line.ix = 1;
	line.iy = 1;
	line.i = 0;
	if (a.z <= 1 && a.z >= -1 && b.z <= 1 && b.z >= -1)
		line.color = WHITE;
	else
		line.color = RED;
	bresenham(img, line);
	return (0);
}
