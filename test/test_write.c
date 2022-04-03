#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define INPUT_SIZE 10000000
char data[INPUT_SIZE];

int main(void)
{
	int		fd;
	int		flags;
	ssize_t	ret;

	fd = open("/home/oligo/write_test/a", O_APPEND | O_WRONLY);
	memset(data, 'A', INPUT_SIZE);
	flags = fcntl(fd, F_GETFL);
	printf("%#o\n", flags);
	ret = write(fd, data, INPUT_SIZE);
	printf("ret=[%zd]\n", ret);
	perror(NULL);
	close(fd);
}
