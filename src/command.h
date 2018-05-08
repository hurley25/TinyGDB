#ifndef COMMAND_H
#define COMMAND_H

#define MAX_ARGS_NUM 128

static const struct command {
  const char *cmd;
  const char *synopsis;
  const char *desc;
} tinygdb_commands[] = {
    {
        "help",
        " command ",
        "Show command description"
    },
    {
        "file",
        " path",
        "Use FILE as program to be debugged"
    },
    {
        "list",
        "",
        "List specified function or line"
    },
    {
        "break",
        " [lineno|function]",
        "Set breakpoint at specified location"
    },
    {
        "run",
        " args",
        "Start debugged program"
    },
    {
        "print",
        " EXP",
        "Print value of expression EXP"
    },
    {
        "set",
        " VAR value",
        "Assign value to variable VAR"
    },
    {
        "info break",
        "",
        "Show breakpoint info"
    },
    {
        "info regs",
        "",
        "show register info"
    },
    {
        "kill",
        "",
        "Kill execution of program being debugged"
    }
};

int parse_command_line(char *command_line);

#endif // COMMAND_H
