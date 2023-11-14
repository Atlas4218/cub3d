/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:58:06 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:23:19 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexlen(unsigned	int hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(unsigned int hex, const char format)
{
	if (hex >= 16)
	{
		ft_puthex(hex / 16, format);
		ft_puthex(hex % 16, format);
	}
	else
	{
		if (hex <= 9)
			ft_printchar(hex + '0');
		else
		{
			if (format == 'x')
				ft_printchar(hex - 10 + 'a');
			if (format == 'X')
				ft_printchar(hex - 10 + 'A');
		}
	}
}

int	ft_printhex(unsigned int hex, const char format)
{
	if (hex == 0)
		return (write(1, "0", 1));
	else
		ft_puthex(hex, format);
	return (ft_hexlen(hex));
}
