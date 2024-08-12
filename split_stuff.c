/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:05:46 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 22:05:49 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_func(char **splited, int i)
{
	while (i--)
		free (splited[i]);
	free (splited);
}

void	word_malloc(char **splited, char const *s1, char c, int nw)
{
	int		i;
	int		start;
	size_t	len;

	i = -1;
	start = 0;
	while (++i < nw)
	{
		len = 0;
		while (s1[start] && s1[start] == c)
			start++;
		while (s1[start] && s1[start] != c)
		{
			start++;
			len++;
		}
		splited[i] = ft_substr(s1, start - len, len);
		if (!splited[i])
			free_func(splited, i);
	}
}

int	count_words(char const *s1, char c)
{
	int	i;
	int	nbr_s;

	i = 0;
	nbr_s = 0;
	while (s1[i])
	{
		if (s1[i] != c)
		{
			nbr_s++;
			while (s1[i] && s1[i] != c)
				i++;
		}
		if (s1[i])
			i++;
	}
	return (nbr_s);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	splited = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!(splited))
		exit (0);
	word_malloc(splited, s, c, count_words(s, c));
	splited[count_words(s, c)] = NULL;
	return (splited);
}

void	free_spl(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}