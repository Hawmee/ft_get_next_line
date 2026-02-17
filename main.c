/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varandri <varandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:08:14 by varandri          #+#    #+#             */
/*   Updated: 2026/02/17 08:41:59 by varandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char *res;
	// res = get_next_line(1);
	int fd;
	
	fd = open("text.txt", O_RDONLY|O_CREAT );
	res = get_next_line(fd);

	printf("%s", res);
	free(res);
	return(0);
}