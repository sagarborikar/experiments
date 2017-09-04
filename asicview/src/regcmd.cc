#include <iostream>
#include <map>

#include "register_cmd.h"

static int info_handler(int argc, char *argv[])
{
    std::cout << "inside info_handler" << std::endl;        
	return 0;    
}

REGISTER_CMD("info", info_handler);

static int find_handler(int argc, char *argv[])
{
    std::cout << "inside find_handler" << std::endl;    
	return 0;    
}

REGISTER_CMD("find", find_handler);

static int read_handler(int argc, char *argv[])
{
    std::cout << "inside read_handler" << std::endl;        
	return 0;    
}

REGISTER_CMD("read", read_handler);

static int write_handler(int argc, char *argv[])
{
    std::cout << "inside write_handler" << std::endl;        
	return 0;    
}

REGISTER_CMD("write", write_handler);
