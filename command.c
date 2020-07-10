#include "command.h"
#include <string.h>


command_t parse_string(char str[]) {
    if(strcmp(str, "start") == 0) {return start;}
    if(strcmp(str, "stop") == 0) {return stop;}
	if(strcmp(str, "status") == 0) {return status;}
	if(strcmp(str, "show") == 0) {return show;}
    if(strcmp(str, "showall") == 0) {return showall;}
	if(strcmp(str, "quit") == 0) {return quit;}
	if(strcmp(str, "help") == 0) {return help;}
	return none;
}

