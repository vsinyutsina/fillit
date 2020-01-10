/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lconchit <lconchit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:45:56 by lconchit          #+#    #+#             */
/*   Updated: 2019/11/10 19:22:28 by lconchit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		join_free(char **line, char const *end_of_line)
{
	char	*tmp;

	tmp = *line;
	if (*line)
	{
		if (!(*line = ft_strjoin(*line, end_of_line)))
		{
			free(tmp);
			tmp = NULL;
			return (0);
		}
		free(tmp);
		tmp = NULL;
		return (1);
	}
	if (!(*line = ft_strdup(end_of_line)))
	{
		free(tmp);
		tmp = NULL;
		return (0);
	}
	free(tmp);
	tmp = NULL;
	return (1);
}

static void		list_free(t_file **file)
{
	if (*file)
	{
		list_free(&(*file)->next);
		free((*file)->content);
		free(*file);
		*file = NULL;
	}
}

static int		read_line(const int fd, char **line, char *end_of_line)
{
	char	*np;
	int		read_bytes;

	if ((np = ft_strchr(end_of_line, '\n')))
	{
		*np = '\0';
		if (!(join_free(line, end_of_line)))
			return (-1);
		end_of_line = ft_strcpy(end_of_line, np + 1);
		return (1);
	}
	if (!(join_free(line, end_of_line)))
		return (-1);
	if ((read_bytes = read(fd, end_of_line, BUFF_SIZE)) > 0)
	{
		end_of_line[read_bytes] = '\0';
		return (read_line(fd, line, end_of_line));
	}
	if (end_of_line[0] != '\0')
	{
		end_of_line[0] = '\0';
		return (1);
	}
	return (read_bytes);
}

t_file			*new_file(int fd)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		return (NULL);
	if (!(new->content = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
	{
		free(new);
		return (NULL);
	}
	new->fd = fd;
	new->next = NULL;
	return (new);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*tmp;
	int				res;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (!file)
		if (!(file = new_file(fd)))
			return (-1);
	tmp = file;
	while (tmp && tmp->fd != fd)
	{
		if (!tmp->next)
			if (!(tmp->next = new_file(fd)))
			{
				list_free(&file);
				return (-1);
			}
		tmp = tmp->next;
	}
	res = read_line(fd, line, tmp->content);
	return (res);
}
