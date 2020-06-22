#include "show_helpers.h"
#include <stdio.h>
#include "util.h"
#include "date.h"

void print_list(void) {
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL){fprintf(stderr, "| Bot> A file is missing.\n");return;}
	
	printf("| ############# WORKING HOURS ###############\n");
	int line_date;
	int line_minutes;
	date_t real_date;
	char line_chars[MAX_STR_SIZE];
	while(!feof(f_time)) {
		fscanf(f_time, "%d", &line_date);
		if(feof(f_time)) {break;}
		fscanf(f_time, "%d", &line_minutes);
		fgets(line_chars, MAX_STR_SIZE, f_time);
		real_date = date_from_int(line_date);

		printf("| #   ");
		print_date(real_date);
		printf(": ");

		int hours = line_minutes/60;
		int minutes = line_minutes%60;

		printf("%02d:%02d (%3d mins)   #\n", hours, minutes, line_minutes);
	}
	printf("| ###########################################\n");
}
