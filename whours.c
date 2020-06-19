#include "command.h"
#include "date.h"
#include "util.h"
#include "help.h"
#include "time.h"
#include <stdio.h>
#include "start_timer.h"
#include "stop_timer.h"
#include "show.h"

int main(void) {
	print_line();
	print_timer_status();
	printf("| Bot> Enter a command (type 'help' for more information).\n");
	char command[MAX_STR_SIZE];
	command_t cmd = none;
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {
		f_time = fopen(FILE_TIME, "w");
		fclose(f_time);
	}
	do {
		printf("| You> ");
		fgets(command, MAX_STR_SIZE, stdin); 
		correct(command);
		cmd = parse_string(command);
	} while(cmd == none);

	while(cmd != quit) {
		print_line();
		switch(cmd) {
			case help: 
				proc_help();
				print_line();
				break;
			case strt:
				proc_strt();
				print_line();
				break;
			case stop:
				proc_stop();
				print_line();
				break;
			case show:
				proc_show();
				print_line();

			default: break;
		}

		do {
        	printf("| You> ");
        	fgets(command, MAX_STR_SIZE, stdin);
        	correct(command);
        	cmd = parse_string(command);
    	} while(cmd == none);
	}
	print_line();
	return 0;
}
