#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define RL_BUFSIZE 1024
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

// Foreground color macro
#define FG_DEFAULT		"\033[39m"
#define FG_BLACK		"\033[30m"
#define FG_DARK_RED		"\033[31m"
#define FG_DARK_GREEN		"\033[32m"
#define FG_DARK_YELLOW		"\033[33m"
#define FG_DARK_BLUE		"\033[34m"
#define FG_DARK_MAGENTA		"\033[35m"
#define FG_DARK_CYAN		"\033[36m"
#define FG_DARK_GRAY		"\033[90m"
#define FG_LIGHT_GRAY		"\033[37m"
#define FG_RED			"\033[91m"
#define FG_GREEN		"\033[92m"
#define FG_YELLOW		"\033[93m"
#define FG_BLUE			"\033[94m"
#define FG_MAGENTA		"\033[95m"
#define FG_CYAN			"\033[96m"
#define FG_WHITE		"\033[97m"

// Background color macro
#define BG_DEFAULT		"\033[49m"
#define BG_BLACK		"\033[40m"
#define BG_DARK_RED		"\033[41m"
#define BG_DARK_GREEN		"\033[42m"
#define BG_DARK_YELLOW		"\033[43m"
#define BG_DARK_BLUE		"\033[44m"
#define BG_DARK_MAGENTA		"\033[45m"
#define BG_DARK_CYAN		"\033[46m"
#define BG_DARK_GRAY		"\033[100m"
#define BG_LIGHT_GRAY		"\033[47m"
#define BG_RED			"\033[101m"
#define BG_GREEN		"\033[102m"
#define BG_YELLOW		"\033[103m"
#define BG_BLUE			"\033[104m"
#define BG_MAGENTA		"\033[105m"
#define BG_CYAN			"\033[106m"
#define BG_WHITE		"\033[107m"

// Reset color
#define CLR_RESET		"\33[0m"

#include "builtin.c"
#include "shell.c"

void loop(char *prompt_config[], size_t prompt_config_size) {

	char *line;
	char **args;
	int status;
	
	do {
		print_prompt(prompt_config, prompt_config_size);
		line = read_line();
		args = split_line(line);
		status = execute(args);
	} while (status);

	free(line);
	free(args);

}

int main(int argc, char **argv) {

	// Config
	#include "config.c"

	size_t prompt_config_size = sizeof(prompt_config) / sizeof(char*);
	
	// Loop
	loop(prompt_config, prompt_config_size);

	// Anything before shutdown or cleanup

	return EXIT_SUCCESS;

}
