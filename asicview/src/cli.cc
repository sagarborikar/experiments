#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <iterator>
#include <readline/readline.h>
#include <readline/history.h>
#include <assert.h>

#include "register_cmd.h"


static char *
dupstr (char *s) {
    char *r;

    r = (char *) calloc(strlen(s) + 1, 1);
    assert(r != NULL);

    strcpy (r, s);
    return (r);
}

static char *
cmd_generator(const char* text, int state)
{
    char *match_ptr;

    if ((match_ptr = match(text, state)) != nullptr) {
        return dupstr(match_ptr);            
    } 
    return NULL;
}

static char **
cmd_completion( const char * text , int start,  int end)
{
    char **matches;

    matches = nullptr;

    if (start == 0)
        matches = rl_completion_matches ((char *)text, &cmd_generator);
    else
        rl_bind_key('\t',rl_abort);

    rl_attempted_completion_over = 1;
    return (matches);

}

static void
process_cmd(char *cmd_buf)
{
    std::cout << "cmd received: " << cmd_buf << std::endl;
}

int
asicview_cli(void)
{
    char *buf;

    rl_attempted_completion_function = cmd_completion;

    while((buf = readline("\n asicview> "))!=NULL) {
        //enable auto-complete
        rl_bind_key('\t',rl_complete);
        if (strncmp(buf,"quit", 4)==0)
            exit(0);
        process_cmd(buf);
    }
    free(buf);
    return 0;
}
