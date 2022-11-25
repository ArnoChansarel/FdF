/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/11/25 14:07:14 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int drawline(t_data set, int x0, int y0, int x1, int y1, int color)
{
	int p;
	int dx;
	int dy;

	dx = x1 - x0;
	dy = y1 - y0;
	if (dx != 0)
	{
		p = (dy / dx) + y0;
		while (x0 <= x1 || y0 <= y1)
		{
			if (p >= 0)
			{
				mlx_pixel_put(set.mlx, set.win, x0, y0, color);
				p = p + 2 * dy - 2 * dx;
				y0 += 1;
			}
			else
			{
				mlx_pixel_put(set.mlx, set.win, x0, y0, color);
				p = p + 2* dy;
			}
			x0 += 1;
		}
	}
	else
	{
		while (y0 <= y1)
		{
			mlx_pixel_put(set.mlx, set.win, x0, y0, color);
			y0 += 1;
		}
	}
	return (0);
}