/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:16:54 by achansar          #+#    #+#             */
/*   Updated: 2023/01/21 11:31:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int	get_height(int *h, char *file_path)
{
	int		fd;
	char	*line;

	*h = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("ERROR : Wrong map dimensions."));
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		*h += 1;
	}
	close(fd);
	return (0);
}

static int	get_width(int w, int fd)
{
	char	*line;
	char	**tabline;

	line = get_next_line(fd);
	while (line)
	{
		tabline = ft_split(line, ' ');
		if (!tabline)
			return (ft_error_msg("ERROR : Split failed."));
		if (!w)
			w = free_tab(tabline);
		else
		{
			if (free_tab(tabline) != w)
			{
				close(fd);
				free(line);
				return (ft_error_msg("ERROR : Wrong map dimensions."));
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (w);
}

int	get_dimensions(t_matrix *matrix, char *file_path)
{
	int	fd;
	int	w;

	w = 0;
	fd = 0;
	matrix->angle = 0.785398;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("ERROR : failed to open file."));
	matrix->w = get_width(w, fd);
	close(fd);
	if (matrix->w <= 0)
		return (1);
	get_height(&matrix->h, file_path);
	if (matrix->h <= 0)
		return (1);
	return (0);
}
