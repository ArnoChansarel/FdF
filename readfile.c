/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:16:54 by achansar          #+#    #+#             */
/*   Updated: 2022/12/16 18:13:39 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

static int get_height(int h, char *file_path)
{
    int fd;
    char *line;
    int i = 0;

    h = 0;
    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    while(line)
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

static int get_width(int w, char *file_path)
{
    int fd;
    char *line;
    char **tabline;

    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        tabline = ft_split(line, ' ');
        if (!w)
            w = check_map_width(tabline);
        else
        {
            if (check_map_width(tabline) != w)
            {
                close(fd);
                free(line);
                return(0);
            }
        }
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (w - 1);
}

int get_dimensions(t_matrix *matrix, char *file_path)
{
    matrix->h = get_height(matrix->h, file_path);
    matrix->w = get_width(matrix->w, file_path);
    if(!matrix->w)
        return(1);
    printf("w = %d | h = %d\n", matrix->w, matrix->h);
    return (0);
}
    