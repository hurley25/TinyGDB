#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <getopt.h>

#include "command.h"
#include "linenoise.h"

void completion(const char *buf, linenoiseCompletions *lc)
{
    int matchlen = strlen(buf);
    size_t len = sizeof(tinygdb_commands) / sizeof(*tinygdb_commands);
    for (size_t i = 0; i < len; ++i) {
        if (!strncmp(buf, tinygdb_commands[i].name, matchlen)) {
            linenoiseAddCompletion(lc, tinygdb_commands[i].name);
        }
    }
}

const char *hints(const char *buf, int *color, int *bold)
{
    *color = 33;
    *bold = 0;
    size_t len = sizeof(tinygdb_commands) / sizeof(*tinygdb_commands);
    for (size_t i = 0; i < len; ++i) {
        if (!strcmp(buf, tinygdb_commands[i].name)) {
            return tinygdb_commands[i].synopsis;
        }
    }

    return NULL;
}

void print_version_info()
{
    fprintf(stderr, "TinyGDB (Version 0.1)\n"
                    "Copyright (C) 2018 XiyouLinuxGroup, Inc.\n"
                    "License MIT: https://mit-license.org/\n"
                    "This is free software: you are free to change and redistribute it.\n"
                    "For bug reporting instructions, please see:\n"
                    "<https://github.com/hurley25/TinyGDB/issues/>\n");
}

int main(int argc, char *argv[])
{
    const char *optstring = "v";
    struct option longopts[] = {
        {"version", 0, NULL, 'v'},
        {0, 0, 0, 0}
    };

    int opt;
    while ((opt = getopt_long(argc, argv, optstring, longopts, NULL)) != -1) {
        switch (opt) {
        case 'v':
            print_version_info();
            return 0;
        }
    }

    // Multi-line mode enabled
    linenoiseSetMultiLine(1);
    // Set max histtory command len
    linenoiseHistorySetMaxLen(1024);

    // Set the completion callback
    linenoiseSetCompletionCallback(completion);
    linenoiseSetHintsCallback(hints);

    print_version_info();

    char *line = NULL;
    while ((line = linenoise("TinyGDB> ")) != NULL) {
        linenoiseHistoryAdd(line);
        parse_command_line(line);
        // Add command to the history
        free(line);
    }

    return 0;
}

