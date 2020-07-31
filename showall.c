#include "showall.h"
#include "util.h"
#include <stdio.h>
#include "showall_helpers.h"
#include "date.h"

void proc_showall(void) {
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {fprintf(stderr, "| Bot> A file is missing.\n");return;}
	int line_count = 0;
	char line[MAX_STR_SIZE];
	while(!feof(f_time)) {
		fgets(line, MAX_STR_SIZE, f_time);
		if(feof(f_time)) {break;}
		line_count += 1;
	}
	fclose(f_time);
	int total_minutes = 0;
	f_time = fopen(FILE_TIME, "r");
	if(feof(f_time) || line_count == 0) {fclose(f_time);printf("| Bot> You have not worked at all yet.\n");return;}
	int line_date;
	int line_mins;
	char useless_chars[MAX_STR_SIZE];
	int max_mins = 0;
	while(!feof(f_time)) {
		fscanf(f_time, "%d", &line_date);
		if(feof(f_time)) {break;}
		fscanf(f_time, "%d", &line_mins);
		if(line_mins > max_mins) {max_mins = line_mins;}
		fgets(useless_chars, MAX_STR_SIZE, f_time);
		total_minutes += line_mins;
	}
	int hours = (total_minutes/line_count)/60;
	int minutes = (total_minutes/line_count)%60;

	int max_hours = max_mins/60;
	int max_minutes = max_mins%60;

	print_list();
	fclose(f_time);
	printf("| Bot> You work on average %d:%02d on working days.\n", hours, minutes);
	f_time = fopen(FILE_TIME, "r");
	int first_date;
	date_t last_date = get_date();
	fscanf(f_time, "%d", &first_date);
	fclose(f_time);
	date_t fd = date_from_int(first_date);
	int diff = day_diff(fd, last_date);
	int tot_hours = (total_minutes/diff)/60;
	int tot_minutes = (total_minutes/diff)%60;
	printf("| Bot> You have worked in average %d:%02d per day since your first working day.\n", tot_hours, tot_minutes); 
	printf("| Bot> Your max work in one day is %d:%02d.\n", max_hours, max_minutes);
}
