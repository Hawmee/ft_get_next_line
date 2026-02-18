/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:46:00 by varandri          #+#    #+#             */
/*   Updated: 2026/02/18 15:15:02 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line_bonus(int fd);

size_t	ft_strlen_bonus(char *str);
void	*ft_calloc_bonus(size_t nmemb, size_t size);
void	*ft_memmove_bonus(void *dest, void *src, size_t n);
char	*ft_strjoin_bonus(char *s1, char *s2);
char	*ft_substr_bonus(char *s, size_t start, size_t len);

#endif