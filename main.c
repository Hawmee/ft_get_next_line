/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:08:14 by varandri          #+#    #+#             */
/*   Updated: 2026/02/17 13:42:40 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *res;
	int fd;
	

	printf("%u", BUFFER_SIZE);
	fd = open("text.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	
	close(fd);
	return(0);
}