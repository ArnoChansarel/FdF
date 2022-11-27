/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 14:57:24 by achansar          #+#    #+#             */
/*   Updated: 2022/11/27 15:03:18 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int open_window(t_data *set)
{
    set->mlx = mlx_init();
	if(!set->mlx)
		return (1);
	set->win = mlx_new_window(set->mlx, WIDTH, HEIGHT, "FdF");
	if(!set->win)
		return (1);
	set->img.img = mlx_new_image(set->mlx, WIDTH, HEIGHT);
	set->img.addr = mlx_get_data_addr(set->img.img, &set->img.bpp, &set->img.szline, &set->img.endian);
    return (0);
}
