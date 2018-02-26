#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"

struct list_head cmd_list;

void cmd_init(void)
{
	INIT_LIST_HEAD(&cmd_list);
}

void cmd_add(const  char *cmd, command_func func, void *data)
{
	struct command *tmp;
	tmp = malloc(sizeof(struct command));

	tmp->cmd = cmd;
	tmp->data = data;
	tmp->func = func;

	list_add_tail(&(tmp->list), &cmd_list);
}

void cmd_del(char *cmd)
{
	struct list_head *tmp;
	struct command *comm;

	list_for_each(tmp, &cmd_list) {
		if(NULL == tmp)
			return;

		comm = (struct command *)list_entry(tmp, struct command, list);
		if (NULL != comm && !strcmp(comm->cmd, cmd)) {
			list_del(&(comm->list));
			free(comm);
		}
	}
}

void cmd_dispatch(char *cmd)
{
	struct list_head *tmp;
	struct command *comm;
	
	list_for_each(tmp, &cmd_list) {
		comm = (struct command *)list_entry(tmp, struct command, list);
		if (!strcmp(comm->cmd, cmd))
			comm->func(comm->data);
	}
}

