#ifndef _CMD_H_
#define _CMD_H_

#include "list.h"

typedef void (*command_func)(void *);

struct command {
	const char *cmd;
	void *data;
	command_func func;
	struct list_head list;	
};

void cmd_init(void);
void cmd_add(const char *cmd, command_func func, void *data);
void cmd_del(char *cmd);
void cmd_dispatch(char *cmd);

#endif

