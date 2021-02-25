/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 14:30:13 by mqueguin          #+#    #+#             */
/*   Updated: 2021/01/08 16:19:26 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_sep(char pos, char c)
{
	if (pos == c || pos == '\0')
		return (1);
	return (0);
}

static int		count_words(char const *s, char c)
{
	int		i;
	int		j;
	int		is_word;

	i = 0;
	j = 0;
	is_word = 0;
	while (s[i])
	{
		if (is_sep(s[i], c))
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			j++;
		}
		i++;
	}
	return (j);
}

static int		count_letters(char const *s, char c, int pos)
{
	int		i;

	i = 0;
	while (s[pos])
	{
		if (!is_sep(s[pos], c))
			i++;
		pos++;
	}
	return (i);
}

static void		split_str(char **tab, char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (s[++i])
	{
		if (!is_sep(s[i], c))
		{
			if (k == 0)
				if (!(tab[j] = malloc(sizeof(char) *
					(count_letters(s, c, i) + 1))))
					return ;
			tab[j][k] = s[i];
			tab[j][k + 1] = '\0';
			k++;
		}
		if ((is_sep(s[i], c) && !is_sep(s[i + 1], c) && k > 0)
			&& (k = 0) == 0)
			j++;
	}
}

char			**ft_split(char const *s, char c)
{
	char		**tab;

	if (!s)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	split_str(tab, s, c);
	tab[count_words(s, c)] = NULL;
	return (tab);
}
