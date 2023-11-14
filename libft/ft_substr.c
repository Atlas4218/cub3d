/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:25:51 by gbonnard          #+#    #+#             */
/*   Updated: 2022/11/26 15:59:18 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcnt(char const *s, unsigned int start, size_t len)
{
	int	i;

	i = 0;
	while ((size_t)i < len && s[start + i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * ft_strcnt(s, start, len) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (j >= start && i < len)
		{
			dest[i] = s[j];
			i++;
		}
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
