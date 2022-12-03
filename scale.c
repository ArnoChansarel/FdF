/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:41 by achansar          #+#    #+#             */
/*   Updated: 2022/11/30 16:03:42 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"


int	scale(t_matrix *ele)
{
	int i;
	int j;

	i = 0;
	while (i < ele->h)
	{
		j = 0;
		while (j < ele->w)
		{
			ele->mtx[i][j].x = ele->mtx[i][j].x * 50 + 800;
			ele->mtx[i][j].y = ele->mtx[i][j].y * 50;
            ele->mtx[i][j].z = ele->mtx[i][j].z * 10;
			j++;
		}
		i++;
	}
	return (0);
}