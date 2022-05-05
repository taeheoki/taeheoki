#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*path;
	pid_t	pid;

	path = getcwd(NULL, 0);
	if (!path)
		return (1);
	printf("Before:\t%s\n", path);
	free(path);
	path = NULL;
	pid = fork();
	if (pid < 0)
		return (1);
	else if (pid == 0)
	{
		if (chdir("../") == -1)
			return(1);
		path = getcwd(NULL, 0);
		if (!path)
			return (1);
		printf("After:\t%s in Child Process\n", path);
		free(path);
		path = NULL;
	}
	else
	{
		sleep(1);
		path = getcwd(NULL, 0);
		if (!path)
			return (1);
		printf("After:\t%s in Parent Process\n", path);
		free(path);
		path = NULL;
	}
	return (0);
}