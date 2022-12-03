/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/30 15:49:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int main(int argc, char *argv[])
{
	t_data 		set;
	t_matrix	matrix;
	
	if (argc != 2)
		return (1);
	open_window(&set);
	get_dimensions(&matrix, argv[1]);
	matrix.mtx = get_matrix(matrix.mtx, argv[1], matrix.h, matrix.w);
	scale(&matrix);
	isometric(&matrix);

	drawline_all(&set.img, matrix.mtx, matrix.w, matrix.h);

	mlx_put_image_to_window(set.mlx, set.win, set.img.img, 0, 0);

	mlx_key_hook(set.win, &destroy, &set);
	
	mlx_loop(set.mlx);
	return (0);
}
