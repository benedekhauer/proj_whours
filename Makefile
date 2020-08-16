whours: whours.o date.o util.o command.o help.o time.o start_timer.o \
 stop_timer.o showall.o stop_timer_helpers.o show.o showall_helpers.o status.o


command.o: command.c command.h
date.o: date.c date.h util.h
help.o: help.c help.h util.h
showall.o: showall.c showall.h util.h showall_helpers.h date.h
showall_helpers.o: showall_helpers.c showall_helpers.h util.h date.h
show.o: show.c show.h date.h util.h
start_timer.o: start_timer.c start_timer.h date.h util.h time.h
status.o: status.c status.h util.h
stop_timer.o: stop_timer.c stop_timer.h date.h util.h \
 stop_timer_helpers.h time.h
stop_timer_helpers.o: stop_timer_helpers.c stop_timer_helpers.h util.h \
 date.h
time.o: time.c time.h
util.o: util.c util.h
whours.o: whours.c command.h date.h util.h help.h time.h start_timer.h \
 stop_timer.h show.h showall.h status.h

libso: whours.c command.c date.c help.c showall.c showall_helpers.c \
 show.c start_timer.c status.c stop_timer.c stop_timer_helpers.c time.c \
 util.c
	@gcc -c -Wall -Werror -fpic *.c 
	@gcc -shared -o libwork.so *.o
	@echo Shared library created

clean: 
	rm *.o whours
