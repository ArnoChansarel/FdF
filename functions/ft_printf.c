/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:50:54 by achansar          #+#    #+#             */
/*   Updated: 2023/01/19 17:50:59 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = ft_convert(str[i + 1], count, args);
			i += 2;
		}
		else
		{
			write(1, &str[i++], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
