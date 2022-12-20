/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:20:41 by achansar          #+#    #+#             */
/*   Updated: 2022/12/20 16:19:38 by achansar         ###   ########.fr       */
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
			ele->mtx[i][j].x = ele->mtx[i][j].x * 20 + 400;
			ele->mtx[i][j].y = ele->mtx[i][j].y * 20;
            ele->mtx[i][j].z = ele->mtx[i][j].z * 5;
			//printf("x = %d | y = %d\n", (int)ele->mtx[i][j].x, (int)ele->mtx[i][j].y);
			j++;
		}
		//printf("nextline\n");
		i++;
	}
	return (0);
}
