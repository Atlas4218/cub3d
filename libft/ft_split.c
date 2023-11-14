/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:53:44 by gbonnard          #+#    #+#             */
/*   Updated: 2022/11/25 13:34:24 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
		i++;
	}
	return (word);
}

static int	ft_size_word(char const *s, char c, int i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		size++;
		i++;
	}
	return (size);
}

static void	ft_free(char **str, int j)
{
	while (j-- > 0)
		free(str[j]);
	free(str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	str = malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	while (++j < ft_count_word(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(s, i, ft_size_word(s, c, i));
		if (!str[j])
		{
			ft_free(str, j);
			return (NULL);
		}
			i += ft_size_word(s, c, i);
	}
	str[j] = 0;
	return (str);
}
