/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/12/20 17:31:37 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
/*
COULEUR + HEXA
LEAKS
FENETRE DYNAMIQUE
NORMINETTE
--
PROJECTION SUPP - PARALLEL
ROTATION
*/

int	open_window(t_data *set)
{
	set->mlx = mlx_init();
	if (!set->mlx)
		return (1);
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "FdF");
	if (!set->win)
		return (1);
	set->img.img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bpp,
			&set->img.szline, &set->img.endian);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	set;

	if (argc == 2)
	{
		open_window(&set);
		if (get_dimensions(&set.matrix, argv[1]) != 0)
			return (ft_error_msg("ERROR : Wrong map dimensions."));
		set.matrix.mtx = get_matrix(set.matrix.mtx, argv[1],
				set.matrix.h, set.matrix.w);
		scale(&set.matrix);
		isometric(&set.matrix);
		drawline_all(&set, &set.img, &set.matrix, set.matrix.mtx);
		mlx_key_hook(set.win, &ft_keys, &set);
		mlx_hook(set.win, 17, 0, &destroy, &set);
		mlx_loop(set.mlx);
	}
	return (0);
}
