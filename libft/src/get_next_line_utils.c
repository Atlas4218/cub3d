/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:11:11 by rastie            #+#    #+#             */
/*   Updated: 2023/01/10 13:30:59 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*ft_strljoin(char const *s1, char const *s2, int size)
{
	char	*result;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	if (!size)
		return (ft_strdup(s1));
	while (s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2[len_s2])
		len_s2++;
	result = malloc(len_s1 + min(size, len_s2) + 1);
	if (result)
	{
		ft_strlcpy(result, s1, len_s1 + 1);
		ft_strlcpy(result + len_s1, s2, min(size, len_s2) + 1);
	}
	return (result);
}
