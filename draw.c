/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/12/14 16:42:05 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

//	L'image est un tableau 1 dimension. On doit donc avec cette formule trouver le bon pixel :
//	soit placer le pointeur a la bonne ligne (szline * y) puis sur la bonne colonne (bpp / 8)
//	en partant du principe que les int sont codes sur 4bits (pourquoi / 8 ??) 
	if (x < WIDTH && x >= 0 && y < HEIGHT && y >= 0)
	{
		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
		*(int *)pixel = color; //                                         => c'est la valeur du pointeur que l'on change
	}
}

int	drawline_all(t_data *set, t_img *img, t_matrix *matrix, t_dot **mtx)
{
	int i;
	int j;
	t_line	line;

	i = 0;
	while (i < matrix->h)
	{
		j = 0;
		while (j < matrix->w)     
		{
			img_pix_put(img, mtx[i][j].x, mtx[i][j].y, RED);
			if (i != matrix->h - 1)
			{
				line = bresenham_init(mtx[i][j].x, mtx[i][j].y, mtx[i+1][j].x, mtx[i+1][j].y);
				bresenham(img, line, WHITE);
			}
			if (j != matrix->w - 1)
			{
				line = bresenham_init(mtx[i][j].x, mtx[i][j].y, mtx[i][j+1].x, mtx[i][j+1].y);
				bresenham(img, line, WHITE);
			}
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(set->mlx, set->win, set->img.img, 0, 0);
	return (0);
}