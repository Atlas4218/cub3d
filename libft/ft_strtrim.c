/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:03:24 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/29 13:21:31 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	str = 0;
	i = 0;
	len = ft_strlen(s1);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
		len--;
	str = malloc(sizeof(char) * (len - i + 1));
	if (!str)
		return (NULL);
	if (str)
		ft_strlcpy(str, &s1[i], len - i + 1);
	return (str);
}
