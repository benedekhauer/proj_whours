#include "start_timer.h"
#include "date.h"
#include <stdio.h>
#include "time.h"

void proc_strt(void) {
	FILE* f_start = fopen(FILE_START, "r");
	if(f_start != NULL) {
		printf("| Bot> The previous timer hasn't been stopped yet.\n");	
		fclose(f_start);
	}
	else {
		FILE* f_time = fopen(FILE_TIME, "r");
		if(f_time == NULL) {
			fprintf(stderr, "| Bot> A file is missing.\n");
			return;
		}
		f_time = fopen(FILE_TIME, "a");
		int today = date_to_int(get_date());
		if(date_exists(today) == FALSE) {
			fprintf(f_time, "%d 0\n", today);
		}

		f_start = fopen(FILE_START, "w");
		fprintf(f_start, "%d", get_nb_mins(get_time()));
		fclose(f_start);
		fclose(f_time);
		time_type now = get_time();
		
		printf("| (%02d:%02d) Bot> Timer STARTED.\n", now.hours, now.minutes);
	}
}
