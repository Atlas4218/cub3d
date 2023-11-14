/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:31:33 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:22:41 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	print_length;

	print_length = 0;
	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[print_length])
	{
		write(1, &str[print_length], 1);
		print_length++;
	}
	return (print_length);
}
