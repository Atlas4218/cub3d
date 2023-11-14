/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 10:57:04 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:22:19 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nb)
{
	int		print_length;
	char	*num;

	print_length = 0;
	num = ft_itoa(nb);
	print_length = ft_printstr(num);
	free(num);
	return (print_length);
}
