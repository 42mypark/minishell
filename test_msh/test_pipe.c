#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#define INPUT_SIZE 1000000
char data[INPUT_SIZE];

int main(void)
{
	int		pfd[2];
	int		flags;
	ssize_t	ret;

	memset(data, 'A', INPUT_SIZE);
	pipe(pfd);
	flags = fcntl(pfd[1], F_GETFL);
	flags |= O_NONBLOCK;
	fcntl(pfd[1], F_SETFL, flags);
	ret = write(pfd[1], data, INPUT_SIZE);
	printf("ret=[%zd]\n", ret);
	close(pfd[0]);
	close(pfd[1]);
}
