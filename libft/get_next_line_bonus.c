/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:53:16 by gbonnard          #+#    #+#             */
/*   Updated: 2023/01/03 13:41:24 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_to_stashb(int fd, char *stash)
{
	char	*buffer;
	int		read_bytes;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchrg(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stash = ft_strjoing(stash, buffer);
	}
	free (buffer);
	return (stash);
}

char	*ft_get_lineb(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_new_stashb(char *stash)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new = malloc(sizeof(char) * (ft_strleng(stash) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		new[j++] = stash [i++];
	new[j] = '\0';
	free (stash);
	return (new);
}

char	*get_next_lineb(int fd)
{
	static char	*stash[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash[fd] = ft_read_to_stashb(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_lineb(stash[fd]);
	stash[fd] = ft_new_stashb(stash[fd]);
	return (line);
}
