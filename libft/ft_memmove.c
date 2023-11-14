/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:42:41 by gbonnard          #+#    #+#             */
/*   Updated: 2022/11/25 12:43:48 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	m;
	char	*s1;
	char	*s2;

	if (!dest && !src)
		return (NULL);
	s1 = (char *)dest;
	s2 = (char *)src;
	m = -1;
	if (s1 > s2)
	{
		while (n > 0)
		{
		((unsigned char *)s1)[n - 1] = ((unsigned char *)s2)[n - 1];
		n--;
		}
	}
	else
	{
		while (++m < n)
		((unsigned char *)s1)[m] = ((unsigned char *)s2)[m];
	}
	return (dest);
}
