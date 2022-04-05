#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int	main()
{
	errno = 0;
	int fd = open("a", O_RDONLY);
	int fd1 = dup(fd);
	int fd2 = dup(fd);

	printf("%d %d %d\n", fd, fd1, fd2);
	close(fd);
	close(fd1);
	printf("%d\n", errno);
	perror(NULL);
	return 0;
}