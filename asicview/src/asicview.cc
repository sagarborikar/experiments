#include <iostream>
#include <map>
#include <string.h>
#include <assert.h>
#include "cap_top_csr.h"
#include "register_cmd.h"

using namespace std;

extern struct cmd_info __start_asicviewcmds;
extern struct cmd_info __stop_asicviewcmds;


struct cmp_str
{
   bool operator()(const char *a, const char *b)
   {
      return strcmp(a, b) < 0;
   }
};

map<char *, cmd_handler_t, cmp_str> cmdmap;
map<char *, cmd_handler_t, cmp_str>::iterator iter;

char *argv[] = {"alpha", "beta", "gamma"};


char *
match(const char *text, int state)
{
    static int len = 0;

    map<char *, cmd_handler_t, cmp_str>::iterator itr;
    if (!state) {
        itr = cmdmap.begin();
        len = strlen (text);
    }
    while (itr != cmdmap.end()) {
        iter++;

        if (strncmp(itr->first, text, len) == 0)
            return (itr->first);
    }
    /* If no names matched, then return NULL. */
    return ((char *)NULL);

}

void
get_cmd_list(char **ptr)
{
    int ncmds = cmdmap.size();

    iter = cmdmap.begin();
    ptr = (char **)calloc(ncmds, 1);
    assert(ptr != nullptr);

    for (int i = 0; i < ncmds; i++) {
        ptr[i] = (char *)calloc(strlen(iter->first) + 1, 1);
        assert(ptr[i] != nullptr);
        strcpy(ptr[i], iter->first);         
    }
}

cap_top_csr_t cap_top;

int main()
{
    vector<cap_csr_base *> cap_csr;
    struct cmd_info *cmd_iter = &__start_asicviewcmds;

    for ( ; cmd_iter < &__stop_asicviewcmds; cmd_iter++) {
        cmdmap.insert(make_pair(cmd_iter->cmd_name, cmd_iter->cmdf));
    }
	// check if command exists
    // Defensive programming
    // handle errors
    //
    for(iter = cmdmap.begin(); iter != cmdmap.end(); iter++) {
        cout << iter->first << endl;
        iter->second(5, argv);
    }
    std::string str("cap_ppa_csr_sta_fifo", strlen("cap_ppa_csr_sta_fifo"));
    cap_csr_base *csr_base = cap_top.search_csr_by_name(str);
    if (csr_base != nullptr) {
        cout << "received element" << csr_base->get_name() << endl;
    }

	cap_csr = cap_top.get_children_string(str);
	vector<cap_csr_base *>::iterator it;
    cout << "received elements: " <<  cap_csr.size() << endl;


	for (it = cap_csr.begin(); it != cap_csr.end(); it++) {
            std::cout << "printing get_name" << endl;
        std::cout << (*it)->get_name() << endl;
	}
    asicview_cli();

}

