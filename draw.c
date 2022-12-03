/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/12/03 15:50:10 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

//	L'image est un tableau 1 dimension. On doit donc avec cette formule trouver le bon pixel :
//	soit placer le pointeur a la bonne ligne (szline * y) puis sur la bonne colonne (bpp / 8)
//	en partant du principe que les int sont codes sur 4bits (pourquoi / 8 ??) 
	if (x < 1920 && x >= 0 && y < 1080 && y >= 0)
	{
		pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
		*(int *)pixel = color; //                                         => ????????
	}
}// =>          attention au segfault si les valeurs depassent INT_MAX/MIN

static int drawline(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int ex;
	int ey;
	int distx;
	int disty;
	int i;
	int ix;
	int iy;

	ix = 1;
	iy = 1;
	if (x0 > x1)
		ix = -1;
	if (y0 > y1)
		iy = -1;
	ex = abs(x1 - x0);//               qu'est-ce qu'on va faire de toi...
	ey = abs(y1 - y0);
	dx = 2 * ex;
	dy = 2 * ey;
	disty = ey;
	distx = ex;
	i = 0;
	if (distx >= disty)
	{
		while (i < distx)
		{
			i++;
			img_pix_put(img, x0, y0, color);
			x0 += ix;
			ex -= dy;
			if (ex < 0)
			{
				ex += dx;
				y0 += iy;
			}
		}
	}
	else if (distx < disty)
	{
		while (i < disty)
		{
			i++;
			img_pix_put(img, x0, y0, color);
			y0 += iy;
			ey -= dx;
			if (ey < 0)
			{
				ey += dy;
				x0 += ix;
			}
		}
	}
	return (0);
}

int	drawline_all(t_img *img, t_dot **mtx, int w, int h)
{
	int i;
	int j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)     
		{
			img_pix_put(img, mtx[i][j].x, mtx[i][j].y, WHITE);
			if (i != h - 1)
				drawline(img, mtx[i][j].x, mtx[i][j].y, mtx[i+1][j].x, mtx[i+1][j].y, WHITE);
			if (j != w - 1)
				drawline(img, mtx[i][j].x, mtx[i][j].y, mtx[i][j+1].x, mtx[i][j+1].y, WHITE);
			j++;
		}
		i++;
	 }
	return (0);
}