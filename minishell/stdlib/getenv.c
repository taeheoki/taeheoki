#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	char	*term;

	term = getenv("TERM");
	if (!term)
		return (1);
	printf("TERM Type is %s\n", term);
	return (0);
}