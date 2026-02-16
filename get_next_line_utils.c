/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:42:04 by varandri          #+#    #+#             */
/*   Updated: 2026/02/16 17:07:39 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char 		*d;
	const unsigned char *s;
	
	if (dest == src || n == 0)
        return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char*)src;
	if(d < s)
		while (n--)
			*(d++) = *(s++);
	else if (d > s)
		while (n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	return (dest);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (nmemb * size))
		((unsigned char *)ptr)[i++] = 0;
	return (ptr);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	res_len;

	res_len = ft_strlen(s1) + ft_strlen(s2);
	res = (char *)ft_calloc(res_len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
		ft_memmove(res, s1, ft_strlen(s1));
	if (s2)
		ft_memmove(res + ft_strlen(s1), s2, ft_strlen(s2));
	return (res);
}

char	*ft_substr(char *s, size_t start, size_t len)
{
	char	*sb;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sb = ft_calloc(1, sizeof(char));
		return (sb);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	sb = (char *)ft_calloc ((len + 1), sizeof(char));
	if (!sb)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sb[i] = s[start + i];
		i ++;
	}
	return (sb);
}