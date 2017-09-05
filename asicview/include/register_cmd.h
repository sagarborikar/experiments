/*
 * Copyright (c) 2007 Pensando ystems, Inc.  All rights reserved.
 */

#ifndef __REGISTER_CMD__H__
#define __REGISTER_CMD__H__

#include <map>
using namespace std;

typedef int (*cmd_handler_t)(int argc, char *argv[]);

struct cmd_info {
    char *cmd_name;
    cmd_handler_t cmdf;
};

char *match(const char *text, int state);
int asicview_cli(void);

#define REGISTER_CMD(name, func) \
    static struct cmd_info __cmd__##func \
        __attribute((__section__("asicviewcmds"))) \
        __attribute((__used__)) = { \
            .cmd_name = #name,  \
            .cmdf = func,    \
        };

void get_cmd_list(char **ptr);
#endif
