#include "shell.h"

/**
 * prompt1 - prints prompt ($ );
 */
void prompt1(void)
{
	write(1, "$", 1);
	write(1, " ", 1);
}
