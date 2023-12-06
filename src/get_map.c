/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:01:52 by gbonnard          #+#    #+#             */
/*   Updated: 2023/12/06 16:39:57 by gbonnard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	void_do_nothing(void *data)
{
	(void)data;
}

void	**list_to_array(t_list *lst)
{
	void	**result;
	void	**temp;
	t_list	*next;

	if (!lst)
		return (NULL);
	if (!lst->content)
		return (ft_lstclear(&lst, &free), NULL);
	temp = malloc((ft_lstsize(lst) + 1) * sizeof(void *));
	if (!temp)
		return (NULL);
	result = temp;
	while (lst)
	{
		*temp = lst->content;
		temp++;
		next = lst->next;
		ft_lstdelone(lst, &void_do_nothing);
		lst = next;
	}
	*temp = NULL;
	return (result);
}

int	get_fd(char *filename)
{
	int		file;
	char	*ext;

	if (!filename)
		return (-1);
	ext = ft_strrchr(filename, '.');
	if (strcmp(ext, ".cub"))
	{
		errno = 22;
		return (perror("Wrong type of file\n"), -1);
	}
	if (open(filename, O_DIRECTORY) >= 0)
		return (perror("Argument is a directory\n"), -1);
	file = open (filename, O_RDONLY, O_NOFOLLOW);
	if (file < 0)
		perror("Couldn't open file\n");
	return (file);
}

char	**get_file(char *filename)
{
	int		file;
	t_list	*result;
	char	*line;

	file = get_fd(filename);
	if (file < 0)
		return (NULL);
	result = NULL;
	line = (char *)1;
	while (line)
	{
		line = get_next_line(file);
		ft_lstadd_back(&result, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	return (close(file), (char **)list_to_array(result));
}
