/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:42:11 by varandri          #+#    #+#             */
/*   Updated: 2026/02/17 14:00:18 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	char *extract_line(char **stash)
{
	size_t	i;
	char	*extracted;
	char	*left_over;

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

static int	check_endl(char *stash)
{
	size_t	i;

	i = 0;
	while (stash && stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i ++;
	}
	return (0);
}

static char	*get_all_line(int fd, char *stash)
{
	ssize_t		b_read;
	char		*tmp;
	char 		*buff;
	
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	b_read = 1;
	while(b_read > 0 && !check_endl(stash))
	{
		b_read = read(fd, buff, BUFFER_SIZE);
		if (b_read < 0)
		{
			free(buff);
			free(stash);
			return (NULL);
		}
		buff[b_read] = '\0';
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;	
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_all_line(fd, stash);
	if (!stash || !(stash)[0])
    {
        free(stash);
		stash = NULL;
        return (NULL);
    }
	line = extract_line(&stash);
	return (line);
}