/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:06:56 by achansar          #+#    #+#             */
/*   Updated: 2022/11/26 16:38:10 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char *pixel;

//	L'image est un tableau 1 dimension. On doit donc avec cette formule trouver le bon pixel :
//	soit placer le pointeur a la bonne ligne (szline * y) puis sur la bonne colonne (bpp / 8)
//	en partant du principe que les int sont codes sur 4bits (pourquoi / 8 ??) 

	pixel = img->addr + (img->szline * y + x * (img->bpp / 8));
	*(int *)pixel = color; //                                         => ????????
}

int drawline(t_img *img, int x0, int y0, int x1, int y1, int color)
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
				img_pix_put(img, x0, y0, color);
				p = p + 2 * dy - 2 * dx;
				y0 += 1;
			}
			else
			{
				img_pix_put(img, x0, y0, color);
				p = p + 2* dy;
			}
			x0 += 1;
		}
	}
	else
	{
		while (y0 <= y1)
			img_pix_put(img, x0, y0++, color);
	}
	return (0);
}