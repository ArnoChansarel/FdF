/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:41 by achansar          #+#    #+#             */
/*   Updated: 2022/12/14 15:47:36 by achansar         ###   ########.fr       */
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
			ele->mtx[i][j].x = ele->mtx[i][j].x * 10 + 200;
			ele->mtx[i][j].y = ele->mtx[i][j].y * 10;
            //ele->mtx[i][j].z = ele->mtx[i][j].z;
			j++;
		}
		i++;
	}
	return (0);
}
