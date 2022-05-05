#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	int	fd;

	fd = open("tesa", O_RDONLY);
	if (fd == -1)
		return (1);
	fd = open("tesa", O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{}
	return (0);
}