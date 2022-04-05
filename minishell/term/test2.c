#include <term.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// #include <readline/readline.h>
// #include <readline/history.h>
#include <termios.h>
#include <unistd.h>
void    set_term_attr(void);
void    get_input(void);

int main(void)
{
        set_term_attr();
        get_input();
}
void    set_term_attr(void)
{
        struct termios  newterm;
        tcgetattr(STDIN_FILENO, &newterm); //현재 터미널 속성 획득
        printf("echo : %lu\n", newterm.c_lflag);
        newterm.c_lflag &= ~(ICANON | ECHO); //논캐노니컬,
        printf("echo : %lu\n", newterm.c_lflag);
        newterm.c_cc[VMIN] = 1;
        newterm.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newterm);
}
void    get_input(void)
{
        char    *line;
        while(1)
        {
                // line = readline("acho> ");
				line = "abc";
                if (!line)
                        break;
                // add_history(line);
                //parsing
                //error check
        }
}