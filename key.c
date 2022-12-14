/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:36:23 by achansar          #+#    #+#             */
/*   Updated: 2022/12/14 12:58:31 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	destroy(t_data *set)
{
	mlx_destroy_image(set->mlx, set->img.img);
	mlx_destroy_window(set->mlx, set->win);
	free(set->mlx);
	exit(0);
	return (0);
}

static int ft_up(t_data *set)
{
	int i;
	int j;

	i = 0;
	while (i < set->matrix.h)
	{
		j = 0;
		while (j < set->matrix.w)
		{
			//ele->mtx[i][j].x = ele->mtx[i][j].x * ;
			set->matrix.mtx[i][j].y -= 15;
        	//ele->mtx[i][j].z = ele->mtx[i][j].z;
			j++;
		}
		i++;
	}
	drawline_all(&set->img, &set->matrix, set->matrix.mtx);
	return (0);
}

int ft_keys(int key, t_data *set)
{

	if (key == 126)
	{
		ft_up(set);
	}
	if (key == ESC)
	{
		destroy(set);
	}
	return (0);
}