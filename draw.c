/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/11/29 19:05:26 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	img_pix_put(t_img *img, int x, int y, int color)
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
}

int drawline(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	float m;
	float dx;
	float dy;
	int x = x0;
	int y = y0;
	float e = 0;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	m = dy / dx;

	//printf("\nm = %f\n\n", m);

	//printf("xy0 = %d, %d || xy1 = %d,%d\n\n---------\n", x0, y0, x1, y1);
	while (x < x1)
	{
		img_pix_put(img, x, y, color);
		x++;
		e -= m;
		if (e <= -0.5)
		{
			e = e + 1;
			y++;
		}
		//printf("x = %d, y = %d || e = %f\n", x, y, e);
	}
	//printf("x,y = %d,%d\n", x, y);
	return (0);
}

int drawline_g(t_img *img, int x0, int y0, int x1, int y1, int color)
{
	float m;
	float dx;
	float dy;
	int x = x0;
	int y = y0;
	float e = 0;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	m = dy / dx;

	while (x > x1)
	{
		img_pix_put(img, x, y, color);
		x--;
		e -= m;
		if (e <= -0.5)
		{
			e = e + 1;
			y++;
		}
	}
	return (0);
}