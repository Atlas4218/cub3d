/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:22:35 by gbonnard          #+#    #+#             */
/*   Updated: 2022/11/17 13:52:50 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long int	nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar_fd('-', fd);
		nn = -nn;
	}
	if (nn >= 10)
	{
		ft_putnbr_fd(nn / 10, fd);
		ft_putchar_fd((nn % 10 + '0'), fd);
	}
	else
		ft_putchar_fd(nn + '0', fd);
}
