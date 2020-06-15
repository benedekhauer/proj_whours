#include "show.h"
#include "util.h"
#include <stdio.h>

void proc_show(void) {
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {fprintf(stderr, "A file is missing.\n");return;}
	double line_count = 0;
	char line[MAX_STR_SIZE];
	while(!feof(f_time)) {
		fgets(line, MAX_STR_SIZE, f_time);
		if(feof(f_time)) {break;}
		line_count += 1.0;
	}
	fclose(f_time);
	double total_minutes = 0;
	f_time = fopen(FILE_TIME, "r");
	if(feof(f_time)) {printf("| WBot> You have not worked at all yet.\n");return;}
	int line_date;
	double line_mins;
	char useless_chars[MAX_STR_SIZE];
	while(!feof(f_time)) {
		fscanf(f_time, "%d", &line_date);
		if(feof(f_time)) {break;}
		fscanf(f_time, "%lf", &line_mins);
		fgets(useless_chars, MAX_STR_SIZE, f_time);
		total_minutes += line_mins;
	}

	printf("| WBot> You work on average %.2lf minutes on working days.\n", total_minutes/line_count);

}
