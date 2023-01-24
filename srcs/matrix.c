/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:01:01 by achansar          #+#    #+#             */
/*   Updated: 2023/01/24 14:11:12 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

t_dot	**free_matrix(t_dot **matrix, int i)
{
	while (i >= 0)
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
	int		i;
	int		fd;
	char	*line;

	line = NULL;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (line);
	i = 0;
	while (i < h)
	{
		line = get_next_line(fd);
		if (!line)
			return (line);
		buff = ft_strjoin_gnl(buff, line);
		free(line);
		i++;
	}
	close(fd);
	return (buff);
}

static t_dot	**create_matrix(t_dot **mtx, t_matrix matrix,
				char **line, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < matrix.h)
	{
		j = 0;
		mtx[i] = malloc(sizeof(t_dot) * matrix.w);
		if (!mtx[i])
			return (free_matrix(mtx, i));
		line = ft_split(map[i], ' ');
		if (!line)
			return (free_matrix(mtx, i));
		while (j < matrix.w)
		{
			mtx[i][j].x = j;
			mtx[i][j].y = i;
			mtx[i][j].z = ft_atoi(line[j]);
			j++;
		}
		free_tab(line);
		i++;
	}
	free_tab(map);
	return (mtx);
}

t_dot	**get_matrix(t_dot **mtx, t_matrix matrix, char *file_path)
{
	char	*buff;
	char	**map;
	char	**line;

	line = NULL;
	mtx = NULL;
	buff = malloc(sizeof(char) * 1);
	if (!buff)
		return (0);
	buff[0] = '\0';
	buff = buffer_map(buff, file_path, matrix.h);
	if (!buff)
		return (mtx);
	map = ft_split(buff, '\n');
	free(buff);
	if (!map)
		return (mtx);
	mtx = malloc(sizeof(t_dot *) * matrix.h);
	if (!mtx)
		return (mtx);
	mtx = create_matrix(mtx, matrix, line, map);
	return (mtx);
}
