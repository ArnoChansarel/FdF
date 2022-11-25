/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:34:01 by achansar          #+#    #+#             */
/*   Updated: 2022/11/25 16:31:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "FdF.h"

char **get_map(int fd, char **map)
{
	int     x, y;
	char    *line;

	/* 1/ On recupere une ligne
		2/ on modifie split pour recuperer la length via un pointeur
		3/ on split par les " "
		4/ on recupere chaque suite d'elements dans un tableau de char.
		5/ on a donc chque valeur dans le bon ordre
	*/
	x = 0;
	y = 0;
	while (y + 1 < 12)
	{
		line = get_next_line(fd);
		map[y] = ft_split(line, ' ');
		free(line);
		//printf("%s", map[y]);
		y++;
	}
	return (map);
}

int ft_fdf()
{
	char    *map[12];
	int fd = open("test_maps/42.fdf", O_RDONLY);

	get_map(fd, map);
	close(fd);
	return (0);
}

/*-------------------------------------------------------*/

int main(void)
{
	//t_data  set;
	
	//set.mlx = mlx_init();
	//set.win = mlx_new_window(set.mlx, 1920, 1080, "Mon bon test");
	
	ft_fdf();
	//drawline(set, 500, 500, 1000, 1000, 0x00FFFFFF);
	//drawline(set, 500, 500, 1000, 500, 0x00FFFFFF);
	//drawline(set, 500, 500, 500, 900, 0x00FFFFFF);

	//mlx_loop(set.mlx);
	//mlx_destroy_image(mlx, image.img);
	//mlx_destroy_window(set.mlx, set.win);

	return (0);
}