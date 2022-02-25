#include <term.h>

int main(void)
{
	NCURSES_CONST char	*temp1 = 0;
	char	*temp2;

	tgetent(temp1, temp2);
	return (0);
}