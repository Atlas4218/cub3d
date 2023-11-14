/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbonnard <gbonnard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:01:52 by gbonnard          #+#    #+#             */
/*   Updated: 2023/11/10 12:20:50 by gbonnard         ###   ########.fr       */
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
	if (!lst->content || !(*(char *)lst->content))
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


char	**get_map(char *filename)
{
	int		file;
	t_list	*result;
	char	*line;

	if (!filename)
		return (NULL);
	if (strcmp(ft_strrchr(filename, '.'), ".cub"))
	{
		errno = 22;
		return (perror("Wrong type of file"), NULL);
	}
	file = open (filename, O_RDONLY);
	if (file < 0)
		return (perror("Couldn't open file"), NULL);
	result = NULL;
	line = (char *)1;
	while (line)
	{
		line = get_next_line(file);
		ft_lstadd_back(&result, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
	}
	close (file);
	return ((char **)list_to_array(result));
}
