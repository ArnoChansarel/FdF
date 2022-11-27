/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/27 15:05:16 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(void)
{
	t_data 		set;
	t_matrix	matrix;
	
	open_window(&set);
	get_dimensions(&matrix);
	matrix.mtx = get_matrix(matrix.mtx, matrix.h, matrix.w);
	//printf("x = %d | y = %d\n", matrix.mtx[8][12].x, matrix.mtx[8][12].y);
	scale(&matrix);
	//printf("x = %d | y = %d\n", matrix.mtx[8][12].x, matrix.mtx[8][12].y);
	
	int i = 0;
	int j;
	while (i < matrix.h)
	{
		j = 0;
		while (j < matrix.w)
		{
			img_pix_put(&set.img, matrix.mtx[i][j].x, matrix.mtx[i][j].y, WHITE);
			j++;
		}
		i++;
	}
	
	mlx_put_image_to_window(set.mlx, set.win, set.img.img, 0, 0);

	mlx_key_hook(set.win, &destroy, &set);
	mlx_loop(set.mlx);

	
	free(set.mlx);
	return (0);
}