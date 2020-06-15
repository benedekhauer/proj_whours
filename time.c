#include "time.h"
#include <time.h>

time_type get_time(void) {
    time_type res;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    res.hours = tm.tm_hour;
    res.minutes = tm.tm_min;
    res.seconds = tm.tm_sec;
    return res;
}


int get_nb_mins(time_type time) {
	return time.hours * 60 + time.minutes;
}
