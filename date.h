#pragma once

#include "util.h"

typedef struct {
	int year;
	int month;
	int day;
} date_t;


date_t get_date(void);

bool_t date_exists(int);

int get_date_minutes(int);

int date_to_int(date_t);

int date_to_days(date_t);
