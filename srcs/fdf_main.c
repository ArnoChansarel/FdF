/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2023/01/20 20:20:00 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	destroy(t_data *set)
{
	free_matrix(set->matrix.mtx, set->matrix.h - 1);
	mlx_destroy_image(set->mlx, set->img.img);
	mlx_destroy_window(set->mlx, set->win);
	exit(0);
}

static int	open_window(t_data *set)
{
	set->mlx = mlx_init();
	if (!set->mlx)
		return (1);
	if (WIDTH < 500 || WIDTH > 2560 || HEIGHT < 500 || HEIGHT > 2000)
		return (ft_error_msg("Wrong window dimensions."));
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "FdF");
	if (!set->win)
		return (1);
	set->img.img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	if (!set->img.img)
	{
		mlx_destroy_window(set->mlx, set->win);
		return (1);
	}
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bpp,
			&set->img.szline, &set->img.endian);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	set;

	if (argc == 2)
	{
		if (get_dimensions(&set.matrix, argv[1]) != 0)
			return (1);
		set.matrix.mtx = get_matrix(set.matrix.mtx, set.matrix, argv[1]);
		if (!set.matrix.mtx)
			return (ft_error_msg("ERROR : Matrix couldn't be created."));
		isometric(&set.matrix);
		if (open_window(&set) != 0)
		{
			free_matrix(set.matrix.mtx, set.matrix.h - 1);
			return (ft_error_msg("ERROR : Failed to open window."));
		}
		drawline_all(&set, &set.img, &set.matrix, set.matrix.mtx);
		mlx_hook(set.win, KEYPRESS, (1L << 0), &ft_keys, &set);
		mlx_hook(set.win, 17, 0, &destroy, &set);
		mlx_loop(set.mlx);
	}
	else
		return (ft_error_msg("ERROR : Only 1 argument is required."));
	return (0);
}
