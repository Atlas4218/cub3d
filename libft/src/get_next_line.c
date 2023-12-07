/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rastie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:10:25 by rastie            #+#    #+#             */
/*   Updated: 2023/01/10 14:30:34 by rastie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*gnl_get_endl(char *buff, int fd)
{
	char	*add;
	char	*temp;
	int		rread;

	if (!buff)
		return (NULL);
	while (!ft_strchr(buff, '\n'))
	{
		temp = buff;
		add = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
		rread = read(fd, add, BUFFER_SIZE);
		if (rread <= 0)
		{
			if (!*buff)
				return (free(temp), free(add), NULL);
			return (free(add), buff);
		}
		buff = ft_strljoin(temp, add, rread);
		free(temp);
		free(add);
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff = NULL;
	char		*temp;
	char		*result;

	if (fd <= 2 && fd)
		return (NULL);
	if (!buff)
		buff = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	buff = gnl_get_endl(buff, fd);
	if (!buff)
		return (NULL);
	temp = buff;
	if (!ft_strchr(buff, '\n'))
	{
		result = ft_strdup(buff);
		buff = NULL;
		return (free(temp), result);
	}
	result = ft_substr(buff, 0, ft_strchr(buff, '\n') - buff + 1);
	buff = ft_strdup(ft_strchr(temp, '\n') + 1);
	return (free(temp), result);
}
