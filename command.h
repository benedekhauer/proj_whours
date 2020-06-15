#pragma once


typedef enum {
	strt,
	stop,
	show,
	quit,
	help,
	none
} command_t;


command_t parse_string(char[]);
