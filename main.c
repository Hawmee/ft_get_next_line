#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int	fd;
	char *res;

	fd = open("text.txt", O_RDONLY);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	res = get_next_line(fd);
	printf("%s", res);
	free(res);
	close(fd);
	return (0);
}