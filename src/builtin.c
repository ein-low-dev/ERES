// # Builtin Commnads

int cd(char **args);
int help(char **args);
int shell_exit(char **args);

char *builtin_str[] = {
	"cd",
	"help",
	"exit"
};

int (*builtin_func[]) (char**) = {
	&cd,
	&help,
	&shell_exit
};

int num_builtins() {
	return sizeof(builtin_str) / sizeof(char *);
}

int cd(char **args) {
	if (args[1] == NULL) {
		fprintf(stderr, "eres: expected argument to \"cd\"");
	} else {
		if (chdir(args[1]) != 0) {
			perror("eres");
		}
	}

	return 1;
}

int help(char **args) {
	int i;
	printf("E.in RE.write S.hell\n");
	printf("Type program name and arguments to run the program.\n");
	printf("Here are built-in shell commands.\n");

	for (i = 0; i < num_builtins(); i++) {
		printf("   %s\n", builtin_str[i]);
	}

	printf("Try using man command to see manual page of the programs.\n");

	return 1;
}

int shell_exit(char **args) {
	return 0;
}

// # Others

// Getting Informations
char dir[1024];
char hostname[1024];
char user[1024];

char *config_str[] = {
	"?user",
	"?hostname",
	"?dir"
};

size_t config_str_len = sizeof(config_str) / sizeof(char*);

char *config_addr[] = {
	user,
	hostname,
	dir
};

void print_prompt(char *config[], size_t config_size) {

	// Put the information in here
	char* login = getlogin();
	if (login != NULL) {
		strncpy(user, login, sizeof(user) - 1);
		user[sizeof(user) - 1] = '\0';
	} else {
		strcpy(user, "unknown");
	}

	if (getcwd(dir, sizeof(dir)) == NULL) perror("eres");	
	gethostname(hostname, sizeof(hostname));


	// Print

	for (int i = 0; i < config_size; i++) {
		int matched = 0;
		
		for (int j = 0; j < config_str_len; j++) {
			if (strcmp(config[i], config_str[j]) == 0) {
				printf("%s", config_addr[j]);
				matched = 1;
				break;
			}
		}

		if (!matched) {
			printf("%s", config[i]);
		}
	}

}



