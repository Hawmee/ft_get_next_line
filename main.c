#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
	int	fd;
	char *res;

	fd = open("a.txt", O_RDONLY);
	
	res = get_next_line(fd);
	while(res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	
	close(fd);
	return (0);
}