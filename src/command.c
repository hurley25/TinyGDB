#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "command.h"

int parse_command_line(char *command_line)
{
    char **cmd_argv = (char **)malloc(sizeof(char *) * MAX_ARGS_NUM);
    int cmd_argc = string_split(command_line, " ", cmd_argv, MAX_ARGS_NUM);

    for (int i = 0; i < cmd_argc; ++i) {
        fprintf(stderr, "%s\n", cmd_argv[i]);
    }

    return 0;
}
