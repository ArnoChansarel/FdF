/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:36:23 by achansar          #+#    #+#             */
/*   Updated: 2022/12/20 16:38:25 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	destroy(t_data *set)
{
	mlx_destroy_image(set->mlx, set->img.img);
	mlx_destroy_window(set->mlx, set->win);
	free(set->mlx);
	free_matrix(set->matrix.mtx, set->matrix.h - 1);
	system("leaks fdf");
	exit(0);
	return (0);
}

static int ft_arrows(t_data *set, int key)
{
	int i;
	int j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == UP)
				set->matrix.mtx[i][j].y -= 50;
			else if (key == DOWN)
				set->matrix.mtx[i][j].y += 50;
			else if (key == LEFT)
				set->matrix.mtx[i][j].x -= 50;
			else if (key == RIGHT)
				set->matrix.mtx[i][j].x += 50;
			j++;
		}
		i++;
	}
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

static int ft_zoom(t_data *set, int key)
{
	int i;
	int j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == ZOOM_IN)
			{
				set->matrix.mtx[i][j].x *= 1.2;
				set->matrix.mtx[i][j].y *= 1.2;
			}
			else if (key == ZOOM_OUT)
			{
				set->matrix.mtx[i][j].x *= 0.8;
				set->matrix.mtx[i][j].y *= 0.8;
			}
			j++;
		}
		i++;
	}
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

static int ft_zscale(t_data *set, int key)
{
	int i;
	int j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			if (key == Z_UP && set->matrix.mtx[i][j].z != 0)
				set->matrix.mtx[i][j].y -= set->matrix.mtx[i][j].z / 2;
			else if (key == Z_DOWN && set->matrix.mtx[i][j].z != 0)
				set->matrix.mtx[i][j].y += set->matrix.mtx[i][j].z / 2;
			j++;
		}
		i++;
	}
	ft_bzero(set->img.addr, HEIGHT * WIDTH * sizeof(int));
	drawline_all(set, &set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

int ft_keys(int key, t_data *set)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_arrows(set, key);
	else if (key == ESC)
		destroy(set);
	else if (key == ZOOM_IN || key == ZOOM_OUT)
		ft_zoom(set, key);
	else if (key == Z_UP || key == Z_DOWN)
		ft_zscale(set, key);
	else
		printf("key pressed = %d\n", key);
	return (0);
}