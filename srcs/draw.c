/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2023/01/19 16:17:28 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
		*(int *)pixel = color;
	}
}

int	drawline_all(t_data *set, t_img *img, t_matrix *matrix, t_dot **mtx)
{
	int		i;
	int		j;

	i = 0;
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	while (i < matrix->h)
	{
		j = 0;
		while (j < matrix->w)
		{
			if (i < matrix->h - 1)
				bresenham_init(img, mtx[i][j], mtx[i + 1][j]);
			if (j < matrix->w - 1)
				bresenham_init(img, mtx[i][j], mtx[i][j + 1]);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	return (0);
}
