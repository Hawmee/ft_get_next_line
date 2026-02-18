/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 09:31:24 by varandri          #+#    #+#             */
/*   Updated: 2026/02/18 11:38:43 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	check_endl(char *stash)
{
	size_t	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*get_all_lines(int fd, char *stash)
{
	char	*buff;
	char	*temp;
	ssize_t	b_read;

	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && !check_endl(stash))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[b_read] = '\0';
		temp = ft_strjoin(stash, buff);
		free(stash);
		stash = temp;
	}
	free(buff);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*extracted;
	char	*left_over;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i ++;
	if ((*stash)[i] == '\n')
		i ++;
	extracted = ft_substr(*stash, 0, i);
	left_over = ft_substr(*stash, i, ft_strlen(*stash) - i);
	free(*stash);
	*stash = left_over;
	return (extracted);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = get_all_lines(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
