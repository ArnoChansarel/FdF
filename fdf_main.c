/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/12/16 18:10:37 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
/*
COULEUR + HEXA
LEAKS
FENETRE DYNAMIQUE
SET XY DYNAMIQUE
SIMPLE PARSING LINE
--
PROJECTION SUPP - PARALLEL
ROTATION
*/

int main(int argc, char *argv[])
{
	t_data	set;
	
	if (argc == 2)
	{
		open_window(&set);
		if (get_dimensions(&set.matrix, argv[1]) != 0)
		{
			printf("ERROR : Wrong map dimensions.\n");
			return (1);
		}
		set.matrix.mtx = get_matrix(set.matrix.mtx, argv[1], set.matrix.h, set.matrix.w);
		scale(&set.matrix);
		isometric(&set.matrix);
		drawline_all(&set, &set.img, &set.matrix, set.matrix.mtx);
		mlx_key_hook(set.win, &ft_keys, &set);
		mlx_hook(set.win, 17, 0, &destroy, &set);
		mlx_loop(set.mlx);
	}
	system("leaks ./fdf");
	return (0);
}
