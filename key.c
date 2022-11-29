/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:36:23 by achansar          #+#    #+#             */
/*   Updated: 2022/11/29 11:43:36 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	destroy(int key, t_data *set)
{
	if (key == ESC)
	{
		mlx_destroy_image(set->mlx, set->img.img);
		mlx_destroy_window(set->mlx, set->win);
		printf("Key pressed = %d\n", key);
		free(set->mlx);
		exit(0);
	}
	return (0);
}