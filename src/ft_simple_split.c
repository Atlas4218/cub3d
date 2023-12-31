/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:48:38 by roman             #+#    #+#             */
/*   Updated: 2023/12/08 16:55:43 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static char	**calcul_malloc(char const *s, char c)
{
	char	**result;
	int		nbelement;

	nbelement = 1;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c)
			nbelement++;
		s++;
	}
	result = malloc((nbelement + 1) * sizeof (*result));
	return (result);
}

char	**ft_simple_split(char const *s, char c)
{
	char		**result;
	char		*element;
	static int	len = 0;
	int			i;

	i = 0;
	result = calcul_malloc(s, c);
	while (*s)
	{
		while (s[len] != c && s[len])
			len++;
		element = ft_substr(s, 0, len);
		s = s + len;
		result[i++] = element;
		len = 0;
		if (*s)
			s++;
	}
	if (i && s[-1] == c)
		result[i++] = ft_strdup("");
	result[i] = NULL;
	return (result);
}
