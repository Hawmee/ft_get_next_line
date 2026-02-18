#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int	fd;
	int fd2;
	char *res;

	fd = open("a.txt", O_RDONLY);
	fd2 = open("b.txt", O_RDONLY);
	
	res = get_next_line_bonus(fd);
	printf("%s", res);
	free(res);
	res = get_next_line_bonus(fd2);
	printf("%s", res);
	free(res);
	
	res = get_next_line_bonus(fd);
	printf("%s", res);
	free(res);
	res = get_next_line_bonus(fd2);
	printf("%s", res);
	free(res);
	
	close(fd);
	close(fd2);
	return (0);
}