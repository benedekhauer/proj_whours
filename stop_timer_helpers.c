#include "stop_timer_helpers.h"
#include "util.h"
#include <stdio.h>
#include "date.h"

void write_new_day(int day1_mins, int day2_mins) {
	write_no_new_day(day1_mins);
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {fprintf(stderr, "A file is missing.\n");return;}
	f_time = fopen(FILE_TIME, "a");
	fprintf(f_time, "%d %d\n", date_to_int(get_date()), day2_mins);
	fclose(f_time);

}


void write_no_new_day(int mins_now) {
	int mins_before = get_date_minutes(date_to_int(get_date()));
	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {fprintf(stderr, "A file is missing.\n");return;}
	FILE* f_swap = fopen(FILE_SWAP, "w");
	int mins_total = mins_now + mins_before;
	int line_date;
	int line_mins;
	char useless_chars[MAX_STR_SIZE];
	while(!feof(f_time)) {
		fscanf(f_time, "%d", &line_date);
		if(feof(f_time)) {break;}
		if(line_date == date_to_int(get_date())) {
			fprintf(f_swap, "%d %d\n", line_date, mins_total);
			break;
		}
		else {
			fscanf(f_time, "%d", &line_mins);
			fgets(useless_chars, MAX_STR_SIZE, f_time);
			fprintf(f_swap, "%d %d%s", line_date, line_mins, useless_chars);
		}
	}
	fclose(f_time);
	fclose(f_swap);
	remove(FILE_TIME);
	rename(FILE_SWAP, FILE_TIME);
}
