#include "libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main()
{
	int fd;
	char **test;

	fd = open("test_gnl", O_RDONLY);
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	close(fd);
	return (0);
}
