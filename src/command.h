#ifndef COMMAND_H
#define COMMAND_H

#define MAX_ARGS_NUM 128

int parse_command_line(char *command_line);

int do_cmd_help(int argc, char **argv);

int do_cmd_file(int argc, char **argv);

int do_cmd_list(int argc, char **argv);

int do_cmd_break(int argc, char **argv);

int do_cmd_run(int argc, char **argv);

int do_cmd_print(int argc, char **argv);

int do_cmd_set(int argc, char **argv);

int do_cmd_info(int argc, char **argv);

int do_cmd_kill(int argc, char **argv);

static const struct command {
  const char *name;
  const char *synopsis;
  const char *desc;
  int (*func)(int, char *[]);
} tinygdb_commands[] = {
    {
        "help",
        " command",
        "Show command description",
        do_cmd_help
    },
    {
        "file",
        " path",
        "Use FILE as program to be debugged",
        do_cmd_file
    },
    {
        "list",
        "",
        "List specified function or line",
        do_cmd_list
    },
    {
        "break",
        " lineno|function",
        "Set breakpoint at specified location",
        do_cmd_break
    },
    {
        "run",
        " args",
        "Start debugged program",
        do_cmd_run
    },
    {
        "print",
        " EXP",
        "Print value of expression EXP",
        do_cmd_print
    },
    {
        "set",
        " VAR value",
        "Assign value to variable VAR",
        do_cmd_set
    },
    {
        "info",
        " break|regs",
        "Show breakpoint or register info",
        do_cmd_info
    },
    {
        "kill",
        "",
        "Kill execution of program being debugged",
        do_cmd_kill
    }
};

#endif // COMMAND_H
