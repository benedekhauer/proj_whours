#pragma once


typedef enum {
	start,
	stop,
	status,
	show,
	showall,
	quit,
	help,
	none
} command_t;


command_t parse_string(char[]);
