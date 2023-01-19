/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:51:19 by achansar          #+#    #+#             */
/*   Updated: 2023/01/19 17:51:21 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] != '\0')
		{
			if (s[i] == c)
				break ;
			i++;
		}
	}
	return (count);
}

static char	**ft_free_split(char **tab, int w)
{
	while (w > 0)
	{
		w--;
		free (tab[w]);
	}
	free (tab);
	tab = NULL;
	return (tab);
}

static char	**ft_intab(char **tab, char *s, char c, int w)
{
	int				j;
	unsigned int	i;
	unsigned int	old_i;

	i = 0;
	j = 0;
	while (j < w)
	{
		while (s[i] != '\0')
		{
			if (s[i] != c)
				break ;
			i++;
		}
		old_i = i;
		while (s[i] != '\0' && s[i] != c)
			i++;
		tab[j] = ft_substr(s, old_i, i - old_i);
		if (!tab[j])
			return (ft_free_split(tab, j));
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	int		words;
	char	**tab;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab = ft_intab(tab, s, c, words);
	return (tab);
}
