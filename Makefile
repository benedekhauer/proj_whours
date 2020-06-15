whours: whours.o date.o util.o command.o help.o time.o start_timer.o \
 stop_timer.o show.o stop_timer_helpers.o

command.o: command.c command.h
date.o: date.c date.h util.h
help.o: help.c help.h util.h
show.o: show.c show.h util.h
start_timer.o: start_timer.c start_timer.h date.h util.h time.h
stop_timer.o: stop_timer.c stop_timer.h date.h util.h \
 stop_timer_helpers.h time.h
stop_timer_helpers.o: stop_timer_helpers.c stop_timer_helpers.h util.h
time.o: time.c time.h
util.o: util.c util.h
whours.o: whours.c command.h date.h util.h help.h time.h start_timer.h \
 stop_timer.h show.h
