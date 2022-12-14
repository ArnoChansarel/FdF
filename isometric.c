/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:56:21 by achansar          #+#    #+#             */
/*   Updated: 2022/12/13 11:47:34 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

float ft_radian(float a)
{
    float f;
    
    f = (a * pi) / 180;
    return (round(f));
}

int isometric(t_matrix  *matrix)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < matrix->h)
    {
        j = 0;
        while (j < matrix->w)
        {
            matrix->mtx[i][j].x = (matrix->mtx[i][j].x - matrix->mtx[i][j].y) * cos(ft_radian(-45));
            matrix->mtx[i][j].y = (matrix->mtx[i][j].x + matrix->mtx[i][j].y) * sin(ft_radian(45)) - matrix->mtx[i][j].z;
            j++;
        }
        i++;
    }
    //printf("x1 = %d | y1 = %d | x2 = %d | y2 = %d\n", matrix->mtx[i][j-1].x, matrix->mtx[i][j-1].y, matrix->mtx[i][j].x, matrix->mtx[i][j].y);
    return (0);
}



