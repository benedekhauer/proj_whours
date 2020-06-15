#pragma once

typedef struct {
	int hours;
	int minutes;
	int seconds;
} time_type;


time_type get_time(void);


int get_nb_mins(time_type);
