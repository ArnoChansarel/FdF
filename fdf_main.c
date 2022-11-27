/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/27 13:50:27 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

/*
int	scale(t_dot **ele)
{
	int i;
	int j;

	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 11)
		{
			ele[i][j].x *= 10;
			ele[i][j].y *= 10;
			j++;
		}
		i++;
	}
	return (0);
}*/


/*-------------------------------------------------------*/

int main(void)
{
	//t_data 		set;
	t_matrix	matrix;
	
	/*set.mlx = mlx_init();
	if(!set.mlx)
		return (1);
	set.win = mlx_new_window(set.mlx, WIDTH, HEIGHT, "FdF");
	if(!set.win)
		return (1);
	set.img.img = mlx_new_image(set.mlx, WIDTH, HEIGHT);
	set.img.addr = mlx_get_data_addr(set.img.img, &set.img.bpp, &set.img.szline, &set.img.endian);
	*/
	get_dimensions(&matrix);
	matrix.mtx = get_matrix(matrix.mtx, matrix.h, matrix.w);
	printf("x = %d | y = %d\n", matrix.mtx[8][12].z, matrix.mtx[8][12].z);
	//scale(matrix.mtx);
	//printf("x = %d | y = %d\n", matrix.mtx[5][5].x, matrix.mtx[5][5].y);
	/*int i = 0;
	int j;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			//scale(&matrix[i+1][j]);
			//img_pix_put(&set.img, matrix[i][j].x, matrix[i][j].y, 0xFFFFFF);
			//drawline(&set.img, matrix.mtx[i][j].x, matrix.mtx[i][j].y, matrix.mtx[i][j+1].x, matrix.mtx[i][j+1].y, 0xFFFFFF);
			//printf("x0 = %d | y0 = %d | x1 = %d | y1 = %d\n", matrix[i][j].x, matrix[i][j].y, matrix[i+1][j].x, matrix[i+1][j].y);
			//drawline(&set.img, matrix[i][j].x, matrix[i][j].y, matrix[i+1][j].x, matrix[i+1][j].y, 0xFFFFFF);
			//printf("x = %d | y = %d\n", matrix[i][j].x, matrix[i][j].y);
			j++;
		}
		i++;
	}*/

	/*
	** . Visiblement l'idee du scale focntionne mais les valeurs ne sont vraiment pas bonnes.
	**   il n'y a qu'a relancer la compil demain matin pour se remettre dedans.
	*/

	//drawline(&set.img, 50, 50, 1000, 1000, 0xFFFFFF);
	
	/*mlx_put_image_to_window(set.mlx, set.win, set.img.img, 0, 0);


	mlx_key_hook(set.win, &destroy, &set);
	mlx_loop(set.mlx);

	
	free(set.mlx);*/
	return (0);
}