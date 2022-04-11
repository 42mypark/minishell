#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv, char **envp)
{
	struct stat buf;
	//access(argv[1], X_OK);
	//execve(argv[1], argv, envp);
	printf("%d\n",lstat(argv[1], &buf));
	printf("%d\n", errno);
	perror(NULL);
	printf("%o\n",buf.st_mode);
}