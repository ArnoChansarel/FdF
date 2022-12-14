/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:16:54 by achansar          #+#    #+#             */
/*   Updated: 2022/12/14 12:44:06 by achansar         ###   ########.fr       */
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
    int i;
    char *line;
    char **tabline;

    fd = open(file_path, O_RDONLY);
    line = get_next_line(fd);
    tabline = ft_split(line, ' ');
    i = 0;
    w = 0;
    while (tabline[i])//     => transformer cette fctn en checker pour justifier l'ouverture complete
    {
        w += 1;
        //printf("ele = %s\n", tabline[i]);
        get_next_line(fd);
        free(tabline[i]);
        i++;
   }
    free(tabline);
    free(line);
    close(fd);
    //printf("w = %d\n", w);
    return (w - 1);
}

int get_dimensions(t_matrix *matrix, char *file_path)
{
    matrix->h = get_height(matrix->h, file_path);
    matrix->w = get_width(matrix->w, file_path);
    printf("w = %d | h = %d\n", matrix->w, matrix->h);
    return (0);
}
    