/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:39:44 by achansar          #+#    #+#             */
/*   Updated: 2022/12/16 18:21:22 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int hextoi(char *hex)
{
    int i;
    int value;
    int byte;

    i = 2;
    value = 0;
    //printf("value hex = %s\n", hex);
    while (hex[i])
    {
        byte = hex[i];
        if (hex[i] >= '0' && hex[i] <= '9')
            byte -= '0';
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            byte = byte - 'a' + 10;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            byte = byte - 'A' + 10;
        value = value * 10 + byte;
        i++;
    }
    //printf("value int = %d\n", value);
    return (value);
}

int check_map_width(char **tabline)
{
    int i;

    i = 0;
    while (tabline[i])
        free(tabline[i++]);
    free(tabline);
    return (i);
}