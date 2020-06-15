#include <stdio.h>
#include <time.h>
#include "date.h"
#include "util.h"


date_t get_date(void) {
	date_t res; 
  	time_t t = time(NULL);
  	struct tm tm = *localtime(&t);
  	res.year = tm.tm_year + 1900;
	res.month = tm.tm_mon+1;
	res.day = tm.tm_mday;
	return res;
}


bool_t date_exists(int date) {
	FILE* file = fopen(FILE_TIME, "r");
	if(file == NULL) {
		fprintf(stderr, "File missing.\n");
		return FALSE;
	}
	int currentDate;
	char useless_line[MAX_STR_SIZE];
	while(!feof(file)) {
		fscanf(file, "%d", &currentDate);
		if(feof(file)) {return FALSE;}
		fgets(useless_line, MAX_STR_SIZE, file);
		if(currentDate == date) {return TRUE;}
	}
}	

int get_date_minutes(int date) {
	if(date_exists(date) == FALSE) {
		return 0;
	}
	FILE* file = fopen(FILE_TIME, "r");
	int current_date;
	int current_mins;
	while(!feof(file)) {
		fscanf(file, "%d", &current_date);
		fscanf(file, "%d", &current_mins);
		if(current_date == date) {return current_mins;}
	}
	return 0;
}

int date_to_int(date_t date) {
	return date.year * 10000 + date.month * 100 + date.day; 
}
