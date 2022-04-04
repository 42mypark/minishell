#include <unistd.h>
#include <stdio.h>

void	print_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		printf("\t %02d : %s\n", i, splited[i]);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	char *args[3] = { "echo", "*", 0};
	print_splited(envp);
	chdir("../");
	printf("\n");
	print_splited(envp);
	execve("/bin/echo", args, NULL);
}