/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/28 19:42:14 by achansar         ###   ########.fr       */
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
	isometric(&matrix);
	
	//printf("x = %d | y = %d\n", matrix.mtx[8][12].x, matrix.mtx[8][12].y);

	int i = 0;
	int j;
	while (i < matrix.h - 1)
	{
		j = 0;
		while (j < matrix.w - 1)     
		{
			img_pix_put(&set.img, matrix.mtx[i][j].x, matrix.mtx[i][j].y, WHITE);
			drawline(&set.img, matrix.mtx[i][j].x, matrix.mtx[i][j].y, matrix.mtx[i+1][j].x, matrix.mtx[i+1][j].y, WHITE);
			drawline(&set.img, matrix.mtx[i][j].x, matrix.mtx[i][j].y, matrix.mtx[i][j+1].x, matrix.mtx[i][j+1].y, WHITE);
			j++;
		}
		i++;
	 }
	// drawline(&set.img, 500, 500, 1000, 1000, WHITE);
	// drawline(&set.img, matrix.mtx[5][5].x, matrix.mtx[5][5].y, matrix.mtx[9][9].x, matrix.mtx[9][9].y, WHITE);

	mlx_put_image_to_window(set.mlx, set.win, set.img.img, 0, 0);

	mlx_key_hook(set.win, &destroy, &set);
	
	mlx_loop(set.mlx);
	return (0);
}