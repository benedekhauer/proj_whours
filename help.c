#include "help.h"
#include "util.h"
#include <stdio.h>

void proc_help(void) {
	print_line();
	printf("|  ####################################\n");
	printf("|  #  help --------- list of commands #\n");
	printf("|  #  strt ---------- start the timer #\n");
	printf("|  #  stop ----------- stop the timer #\n");
	printf("|  #  show ----- show working history #\n");
	printf("|  #  quit --------- quit the program #\n");
	printf("|  ####################################\n");
}
