#include "shell.h"

/** 
 * main - Entry point
 *
 * Return: 0;
 */
int main(void)
{
	while (1)
	{
		prompt1();

		shell_exec();
	}
	return (0);
}