#include "command.h"
#include <string.h>


command_t parse_string(char str[]) {
    if(strcmp(str, "strt") == 0) {return strt;}
    if(strcmp(str, "stop") == 0) {return stop;}
    if(strcmp(str, "show") == 0) {return show;}
	if(strcmp(str, "quit") == 0) {return quit;}
	if(strcmp(str, "help") == 0) {return help;}
	return none;
}

