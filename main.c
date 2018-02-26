#include <stdio.h>
#include "cmd.h"
#include "gpio.h"

static void func1(void * data)
{
	printf("func1\n");
	printf("%s\n", (char *)data);
}

static void func2(void * data)
{
	printf("func2\n");
	printf("%s\n", (char *)data);
}

int main(int argc, char **argv)
{
	cmd_init();

	cmd_add("1", func1, (void *)"Hello");
	cmd_add("2", func2, (void *)"World");
	cmd_add("gpio", gpio_high, (void *)"World");

	cmd_dispatch("1");
	cmd_dispatch("2");
	cmd_dispatch("gpio");

	return 0;
}

