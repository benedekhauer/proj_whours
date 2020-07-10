#pragma once


typedef enum {
	start,
	stop,
	status,
	show,
	quit,
	help,
	none
} command_t;


command_t parse_string(char[]);
