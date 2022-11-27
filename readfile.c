/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:16:54 by achansar          #+#    #+#             */
/*   Updated: 2022/11/27 13:44:01 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int get_height(int h)
{
    int fd;
    char *line;
    int i = 0;

    h = 0;
    fd = open("test_maps/42.fdf", O_RDONLY);
    line = get_next_line(fd);
    while(i < 10)
   {
        free(line);
        line = get_next_line(fd);
        h += 1;
        i++;
    }
    close(fd);
    free(line);
    //printf("h = %d\n", h);
    return (h);
}

static int get_width(int w)
{
    int fd;
    int i;
    char *line;

    fd = open("test_maps/42.fdf", O_RDONLY);
    line = get_next_line(fd);
    close(fd);
    i = 0;
    w = 0;
    while (line[i] && line[i] != '\n')
    {
        if (line[i] == '0')
            w += 1;
        i++;
   }
    free(line);
    //printf("w = %d\n", *w);
    return (w);
}

int get_dimensions(t_matrix *matrix)
{
    matrix->h = get_height(matrix->h);
    matrix->w = get_width(matrix->w);
    //printf("w = %d | h = %d\n", matrix->w, matrix->h);
    return (0);
}
