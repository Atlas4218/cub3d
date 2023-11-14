/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:58:12 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:23:43 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_ulen(unsigned	int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	long int		len;

	len = ft_ulen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_printunbr(unsigned int nb)
{
	int		print_length;
	char	*num;

	print_length = 0;
	if (nb == 0)
		print_length = write(1, "0", 1);
	else
	{
		num = ft_uitoa(nb);
		print_length = ft_printstr(num);
		free(num);
	}
	return (print_length);
}
