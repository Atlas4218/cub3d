/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:59:07 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:23:35 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ptrlen(unsigned	long long ptr)
{
	int	len;

	len = 0;
	while (ptr != 0)
	{
		ptr = ptr / 16;
		len++;
	}
	return (len);
}

void	ft_putptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long ptr)
{
	int	print_length;

	if (ptr == 0)
		print_length = write(1, "(nil)", 5);
	else
	{
		print_length = write(1, "0x", 2);
		ft_putptr(ptr);
		print_length += ft_ptrlen(ptr);
	}
	return (print_length);
}
