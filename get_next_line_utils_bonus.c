/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 14:46:04 by varandri          #+#    #+#             */
/*   Updated: 2026/02/18 15:14:29 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_bonus(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	*ft_calloc_bonus(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	i;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	mem = malloc (nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
	{
		((unsigned char *)mem)[i] = (unsigned char)0;
		i ++;
	}
	return ((void *)mem);
}

void	*ft_memmove_bonus(void *dest, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (dest == src || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n --)
			*(d++) = *(s++);
	}
	if (d > s)
	{
		while (n)
		{
			d[n - 1] = s[n - 1];
			n --;
		}
	}
	return (dest);
}

char	*ft_strjoin_bonus(char *s1, char *s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen_bonus(s1);
	s2_len = ft_strlen_bonus(s2);
	res = (char *)ft_calloc_bonus((s1_len + s2_len + 1), sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
		ft_memmove_bonus(res, s1, s1_len);
	if (s2)
		ft_memmove_bonus(res + s1_len, s2, s2_len);
	return (res);
}

char	*ft_substr_bonus(char *s, size_t start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen_bonus(s))
		return (NULL);
	if (len >= ft_strlen_bonus(s + start))
		len = ft_strlen_bonus(s + start);
	sub = (char *)ft_calloc_bonus(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	return (sub);
}