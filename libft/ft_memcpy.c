/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:56:18 by gbonnard          #+#    #+#             */
/*   Updated: 2022/11/25 12:12:53 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	m;
	char	*str;

	if (!dest && !src)
		return (NULL);
	str = (char *)dest;
	m = 0;
	while (m < n)
	{
		((unsigned char *)str)[m] = ((unsigned char *)src)[m];
		m++;
	}
	return (dest);
}
