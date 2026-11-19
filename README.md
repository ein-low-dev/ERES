# ERES

## A basic shell written in C. Easy to configure.

ERES or Ein Rewrite a Shell is a _simple shell, configurable_. I add __16 colors__ but it's hard for manually write ```\033[XXXm``` so i made a macro manually.

I also use multiple source files for more organized.

### Features

1. It had __3 built-in shell commands__ (cd, help, exit)
2. __Configurable in _config.c_ file.__
3. __16 Colors__ foreground and background for the text.

### Compile

You need ```cc```. I use that because it also work on _solaris_.

To build/compile:
```bash
make build
```

To run:
```bash
make run
```

To build and run:
```bash
make build run
```

To remove the executable file:
```bash
make clean
```

### Improvement for next

This shell already good for me, but it can be better. I might want to add __history__ like bash and __tab completion__ for more easier running commands.
