#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"
#include "command.h"

int parse_command_line(char *command_line)
{
    char **argv = (char **)malloc(sizeof(char *) * MAX_ARGS_NUM);
    int argc = string_split(command_line, " ", argv, MAX_ARGS_NUM);

    if (argc < 1) {
        return -1;
    }

    size_t len = sizeof(tinygdb_commands) / sizeof(*tinygdb_commands);
    for (size_t i = 0; i < len; ++i) {
        if (strcmp(tinygdb_commands[i].name, argv[0]) == 0) {
            return tinygdb_commands[i].func(argc, argv);
        }
    }
    fprintf(stderr, "not support command `\e[1;31m%s\e[0m`\n", argv[0]);

    return -1;
}

static void print_one_commamd_info(const struct command *cmd)
{
    if (strlen(cmd->synopsis) != 0) {
        fprintf(stderr, "%s\e[1;33m%s\e[0m  \e[1;34m%s\e[0m\n", cmd->name, cmd->synopsis, cmd->desc);
    } else {
        fprintf(stderr, "%s  \e[1;34m%s\e[0m\n", cmd->name, cmd->desc);
    }
}

int do_cmd_help(int argc, char **argv)
{
    size_t len = sizeof(tinygdb_commands) / sizeof(*tinygdb_commands);

    if (argc > 1) {
        for (size_t i = 0; i < len; ++i) {
            if (strcmp(tinygdb_commands[i].name, argv[1]) == 0) {
                print_one_commamd_info(&tinygdb_commands[i]);
                return 0;
            }
        }
        fprintf(stderr, "not found help info for command `\e[1;31m%s\e[0m`\n", argv[1]);
    } else {
        fprintf(stderr, "List of classes of commands:\n\n");
        for (size_t i = 0; i < len; ++i) {
            print_one_commamd_info(&tinygdb_commands[i]);
        }
        fprintf(stderr, "\n");
    }

    return 0;
}

int do_cmd_file(int argc, char **argv)
{
    return 0;
}

int do_cmd_list(int argc, char **argv)
{
    return 0;
}

int do_cmd_break(int argc, char **argv)
{
    return 0;
}

int do_cmd_run(int argc, char **argv)
{
    return 0;
}

int do_cmd_print(int argc, char **argv)
{
    return 0;
}

int do_cmd_set(int argc, char **argv)
{
    return 0;
}

int do_cmd_info(int argc, char **argv)
{
    return 0;
}

int do_cmd_kill(int argc, char **argv)
{
    return 0;
}

