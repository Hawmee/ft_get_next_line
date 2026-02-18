/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:45:58 by varandri          #+#    #+#             */
/*   Updated: 2026/02/18 17:17:04 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	check_endl_bonus(char *stash)
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

static char	*get_all_lines_bonus(int fd, char *stash)
{
	char	*buff;
	char	*temp;
	ssize_t	b_read;

	buff = (char *)ft_calloc_bonus(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	b_read = 1;
	while (b_read > 0 && !check_endl_bonus(stash))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[b_read] = '\0';
		temp = ft_strjoin_bonus(stash, buff);
		free(stash);
		stash = temp;
	}
	free(buff);
	return (stash);
}

static char	*extract_line_bonus(char **stash)
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
	extracted = ft_substr_bonus(*stash, 0, i);
	left_over = ft_substr_bonus(*stash, i, ft_strlen_bonus(*stash) - i);
	free(*stash);
	*stash = left_over;
	return (extracted);
}

char	*get_next_line_bonus(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > 1024)
		return (NULL);
	stash[fd] = get_all_lines_bonus(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line_bonus(&stash[fd]);
	return (line);
}
