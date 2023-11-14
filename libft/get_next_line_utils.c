/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:53:19 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:48:18 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strleng(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchrg(char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (NULL);
}

static size_t	ft_strlcpyg(char *dst, char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (--size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
	i++;
	return (i);
}

size_t	ft_strlcatg(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (!dst && !size)
		return (0);
	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strleng(src));
}

char	*ft_strjoing(char *s1, char *s2)
{
	char	*s3;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strleng(s1) + ft_strleng(s2) + 1));
	if (!s3)
		return (NULL);
	ft_strlcpyg(s3, s1, ft_strleng(s1) + 1);
	ft_strlcatg(s3, s2, ft_strleng(s1) + ft_strleng(s2) + 1);
	free(s1);
	return (s3);
}
