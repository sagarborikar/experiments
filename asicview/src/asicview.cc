#include <iostream>
#include <map>
//#include "cap_top_csr.h"
#include <string.h>
#include "register_cmd.h"

using namespace std;
typedef int (*cmd_handler)(int argc, char *argv[]);

extern struct cmd_info __start_asicviewcmds;
extern struct cmd_info __stop_asicviewcmds;

struct cmp_str
{
   bool operator()(char const *a, char const *b)
   {
      return strcmp(a, b) < 0;
   }
};

map<char *, cmd_handler, cmp_str> cmdmap;
map<char *, cmd_handler>::iterator iter;

int main()
{
//	cap_top_csr_t cap_top;
//	vector<cap_csr_base *> cap_csr;
//
    char *argv[] = {"alpha", "beta", "gamma"};		
    struct cmd_info *cmd_iter = &__start_asicviewcmds;

    for ( ; cmd_iter < &__stop_asicviewcmds; cmd_iter++) {
        cmdmap.insert(make_pair(cmd_iter->cmd_name, cmd_iter->cmdf));
    }
	// check if command exists
    // Defensive programming
    // handle errors
    //
	cap_csr = cap_top.get_children("cap_dpp");
    for(iter = cmdmap.begin(); iter != cmdmap.end(); iter++) {
        cout << iter->first << endl;
        iter->second(5, argv); 
    }
	vector<cap_csr_base *>::iterator it;
	for (it = cap_csr.begin(); it != cap_csr.end(); it++) {
		cout << (*it).first << endl;	
	}	
}

