/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:56:21 by achansar          #+#    #+#             */
/*   Updated: 2022/12/19 17:27:52 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static float	ft_radian(float a)
{
	float	f;

	f = (a * M_PI) / 180;
	return (round(f));
}

int	isometric(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < matrix->h)
	{
		j = 0;
		while (j < matrix->w)
		{
			matrix->mtx[i][j].x = (matrix->mtx[i][j].x - matrix->mtx[i][j].y)
				* cos(ft_radian(-45));
			matrix->mtx[i][j].y = (matrix->mtx[i][j].x + matrix->mtx[i][j].y)
				* sin(ft_radian(45)) - matrix->mtx[i][j].z;
			j++;
		}
		i++;
	}
	return (0);
}
