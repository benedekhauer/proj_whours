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
	return FALSE;
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

date_t date_from_int(int number) {
	date_t res;
	int year = number/10000;
	int monthday = number - year*10000;
	int month = monthday / 100;
	int day = monthday - month*100;

	res.year = year;
	res.month = month;
	res.day = day;
	return res;
}

void print_month(int month) {
	switch(month) {
		case 1: printf(" January ");break;
		case 2: printf(" February");break;
		case 3: printf("  March  ");break;
		case 4: printf("  April  ");break;
		case 5: printf("   May   ");break;
		case 6: printf("   June  ");break;
		case 7: printf("   July  ");break;
		case 8: printf(" August  ");break;
		case 9: printf("September");break;
	    case 10: printf(" October ");break;
	    case 11: printf(" November");break;
	    case 12: printf(" December");break;
		default: printf("---------");
	}
}


void print_date(date_t date) { 
	printf("%02d ", date.day);
	print_month(date.month);
	printf(" %04d", date.year);

}

bool_t is_leap(int year) {
	return (year % 4 == 0) ? TRUE : FALSE;
}

int days_since_20200101(date_t d) {
	int d_total_days = d.day;

	for(int i = 2020; i < d.year; i++) {
		if(is_leap(i) == TRUE) {
			d_total_days += 366;
		}
		else {
			d_total_days += 365;
		}
	}

	switch(d.month) {
		case 12: d_total_days += 30;
		case 11: d_total_days += 31;
		case 10: d_total_days += 30;
		case 9: d_total_days += 31;
		case 8: d_total_days += 31;
		case 7: d_total_days += 30;
		case 6: d_total_days += 31;
		case 5: d_total_days += 30;
		case 4: d_total_days += 31;
		case 3: d_total_days += (is_leap(d.year) == TRUE) ? 29 : 28;
		case 2: d_total_days += 31;
		case 1: d_total_days += 0;
		default: d_total_days += 0;
	}

	return d_total_days;

}


int day_diff(date_t d1, date_t d2) {
	int d1days = days_since_20200101(d1);
	int d2days = days_since_20200101(d2);
	
	return (d1days > d2days) ? 1 + d1days-d2days : 1 + d2days - d1days;
}
