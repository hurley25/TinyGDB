#ifndef COMMAND_H
#define COMMAND_H

static const struct command {
  const char *cmd;
  const char *synopsis;
  const char *desc;
} tinygdb_commands[] = {
    {
        "info regs",
        "",
        "show register info"
    }
};

#endif // COMMAND_H
