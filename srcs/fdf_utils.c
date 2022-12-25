/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:39:44 by achansar          #+#    #+#             */
/*   Updated: 2022/12/25 17:27:24 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	free_tab(char **tab)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (tab[i])
	{
		if (*tab[i] != '\n')
			c++;
		free(tab[i++]);
	}
	free(tab);
	return (c);
}

int	ft_error_msg(char *str)
{
	ft_printf("%s\n", str);//               => remener ft_printf
	return (-1);
}
