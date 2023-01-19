/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:56:21 by achansar          #+#    #+#             */
/*   Updated: 2023/01/19 16:20:50 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	scale(t_matrix *ele)
{
	int	i;
	int	j;

	i = 0;
	while (i < ele->h)
	{
		j = 0;
		while (j < ele->w)
		{
			ele->mtx[i][j].x = ele->mtx[i][j].x * 20 + 500;
			ele->mtx[i][j].y = ele->mtx[i][j].y * 20;
			ele->mtx[i][j].z = ele->mtx[i][j].z * 5;
			j++;
		}
		i++;
	}
	return (0);
}

int	isometric(t_matrix *matrix)
{
	int	i;
	int	j;

	i = 0;
	scale(matrix);
	while (i < matrix->h)
	{
		j = 0;
		while (j < matrix->w)
		{
			matrix->mtx[i][j].x = (matrix->mtx[i][j].x - matrix->mtx[i][j].y)
				* cos(matrix->angle);
			matrix->mtx[i][j].y = (matrix->mtx[i][j].x + matrix->mtx[i][j].y)
				* sin(matrix->angle) - matrix->mtx[i][j].z;
			j++;
		}
		i++;
	}
	return (0);
}
