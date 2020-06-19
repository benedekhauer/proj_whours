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

date_t date_from_int(int);

void print_month(int);

void print_date(date_t);

bool_t is_leap(int);

int days_since_20200101(date_t);

int day_diff(date_t, date_t);
