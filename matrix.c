/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:01:01 by achansar          #+#    #+#             */
/*   Updated: 2022/12/16 16:45:17 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int get_color(char *ele, t_dot *dot)
{
	int i;
	char **tab;

	i = 0;
	tab = ft_split(ele, ',');
	dot->z = atoi(tab[0]);
	dot->color = hextoi(tab[1]);
	while(tab[i])
		free(tab[i++]);
	free(tab);
	return (0);
}

static t_dot	**free_matrix(t_dot **matrix, int i)
{
	while(i)
	{
		free(matrix[i]);
		i--;
	}
	free(matrix);
	matrix = NULL;
	return (matrix);
}

static char	*buffer_map(char *buff, char *file_path, int h)
{
	int     i;
	int		fd;
	char    *line = NULL;

	fd = open(file_path, O_RDONLY);
	i = 0;
	while (i < h)
	{
		line = get_next_line(fd);
		buff = ft_strjoin_gnl(buff, line);
		free(line);
		i++;
	}
	close(fd);
	return (buff);
}

static t_dot	**create_matrix(int h, int w, char **tab)
{
	int		i;
	int		j;
	char	**line;
	t_dot	**matrix;
	
	matrix = malloc(sizeof(t_dot *) * h);
	if (!matrix)
		return (matrix);
	i = 0;
	while (i < h)
	{
		j = 0;
		matrix[i] = malloc(sizeof(t_dot) * w);
		if (!matrix[i])
			return(free_matrix(matrix, i));
		line = ft_split(tab[i], ' ');
		while (j < w)
		{
			matrix[i][j].x = j;
			matrix[i][j].y = i;
			if (ft_isin(line[j], ',') != 1)
				get_color(line[j], &matrix[i][j]);
			else
			{
				matrix[i][j].z = ft_atoi(line[j]);
				matrix[i][j].color = WHITE;
			}
			free(line[j]);
			j++;
		}
		i++;
	}
	free(line);
	return (matrix);
}

t_dot **get_matrix(t_dot **mtx, char *file_path, int h, int w)
{
	char	*buff;
	char	**map;

	buff = malloc(sizeof(char) * 1);
	if (!buff)
		return (0);
	buff[0] = '\0';
	buff = buffer_map(buff, file_path, h);
	map = ft_split(buff, '\n');
	free(buff);
    mtx = create_matrix(h, w, map);
	return (mtx);
}