/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/11/30 16:56:07 by achansar         ###   ########.fr       */
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
	float m;
	float dx;
	float dy;
	float e = 0;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	m = dy / dx;

	//printf("\nm = %f\n\n", m);

	//printf("xy0 = %d, %d || xy1 = %d,%d\n\n---------\n", x0, y0, x1, y1);
	while (x0 < x1)
	{
		img_pix_put(img, x0, y0, color);
		x0++;
		e -= m;
		if (e <= -0.5)
		{
			e = e + 1;
			y0++;
		}
		//printf("x = %d, y = %d || e = %f\n", x, y, e);
	}
	//printf("x,y = %d,%d\n", x, y);
	return (0);
}

static int drawline_g(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	float m;
	float dx;
	float dy;
	float e = 0;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	m = dy / dx;

	while (x0 > x1)
	{
		img_pix_put(img, x0, y0, color);
		x0--;
		e -= m;
		if (e <= -0.5)
		{
			e = e + 1;
			y0++;
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
				drawline_g(img, mtx[i][j].x, mtx[i][j].y, mtx[i+1][j].x, mtx[i+1][j].y, WHITE);
			if (j != w - 1)
				drawline(img, mtx[i][j].x, mtx[i][j].y, mtx[i][j+1].x, mtx[i][j+1].y, WHITE);
			j++;
		}
		i++;
	 }
	return (0);
}