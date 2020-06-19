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

void print_timer_status(void) {
	FILE* f_start = fopen(FILE_START, "r");
	if(f_start == NULL) {
		printf("| Bot> Timer status: stopped.\n");
	}
	else {
		fclose(f_start);
		printf("| Bot> Timer status: running...\n");
	}
}
