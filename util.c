#include "util.h"
#include <stdio.h>

void correct(char str[]) {
	for(int i = 0; i < MAX_STR_SIZE; i++) {
		if(str[i] == '\n') {
			str[i] = '\0';
			return;
		}
	}
}


void print_line(void) {
	printf("| -------------------------------------------------------------------------\n");}
