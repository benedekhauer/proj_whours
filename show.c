#include "show.h"
#include "date.h"
#include <stdio.h>

void proc_show(void) {
	int today = date_to_int(get_date());


	FILE* f_time = fopen(FILE_TIME, "r");
	if(f_time == NULL) {
		printf("| Bot> A file is missing.\n");
		return;
	}
	fclose(f_time);
	FILE* f_start = fopen(FILE_START, "r");
	if(f_start != NULL) {
		fclose(f_start);
		printf("| Bot> Stop the timer for precise values.\n");
		return;
	}

	if(date_exists(today) == FALSE || get_date_minutes(today) == 0) {
		printf("| Bot> You have not worked yet today.\n");
		return;
	}

	int mins = get_date_minutes(today);
	int worked_hours = mins/60;
	int worked_mins = mins%60;
	printf("| Bot> You have worked %02dh%02d today.\n", worked_hours, worked_mins);

}
