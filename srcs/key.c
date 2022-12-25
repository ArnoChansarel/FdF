/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:36:23 by achansar          #+#    #+#             */
/*   Updated: 2022/12/25 12:55:51 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	ft_rotate(t_data *set, int key)
{
	// int	i;

	if (key == ROT_L)
		set->matrix.angle -= 0.05;
	else if (key == ROT_R)
		set->matrix.angle += 0.05;
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	isometric(&set->matrix);
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

static int	ft_arrows(t_data *set, int key)
{
	int	i;
	int	j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == UP)
				set->matrix.mtx[i][j].y -= 10;
			else if (key == DOWN)
				set->matrix.mtx[i][j].y += 10;
			else if (key == LEFT)
				set->matrix.mtx[i][j].x -= 10;
			else if (key == RIGHT)
				set->matrix.mtx[i][j].x += 10;
			j++;
		}
		i++;
	}
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

static int	ft_zoom(t_data *set, int key)
{
	int	i;
	int	j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == ZOOM_IN)
			{
				set->matrix.mtx[i][j].x *= 1.02;
				set->matrix.mtx[i][j].y *= 1.02;
			}
			else if (key == ZOOM_OUT)
			{
				set->matrix.mtx[i][j].x *= 0.98;
				set->matrix.mtx[i][j].y *= 0.98;
			}
			j++;
		}
		i++;
	}
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

static int	ft_zscale(t_data *set, int key)
{
	int	i;
	int	j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == Z_UP && set->matrix.mtx[i][j].z != 0)
				set->matrix.mtx[i][j].y -= set->matrix.mtx[i][j].z * 0.2;
			else if (key == Z_DOWN && set->matrix.mtx[i][j].z != 0)
				set->matrix.mtx[i][j].y += set->matrix.mtx[i][j].z * 0.2;
			j++;
		}
		i++;
	}
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

int	ft_keys(int key, t_data *set)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_arrows(set, key);
	else if (key == ESC)
		destroy(set);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom(set, key);
	else if (key == Z_UP || key == Z_DOWN)
		ft_zscale(set, key);
	else if (key == ROT_L || key == ROT_R)
		ft_rotate(set, key);
	// else
	// 	printf("key pressed = %d\n", key);
	return (0);
}
