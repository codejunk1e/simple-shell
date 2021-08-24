#include "shell.h"

/**
 * _getenv - gets $PATH
 *
 * Return: Double pointer to variable path
 */
char *_getenv(void)
{
	int index, len;
	char *var = "PATH";

	len = _strlen(var);
	for (index = 0; environ[index]; index++)
	{
		if (_strncmp(var, environ[index], len) == 0)
			return (environ[index]);
	}

	return (NULL);
}

/**
 *
 */
void shell_exec(void)
{
	int status, cnt;
	const char *pathname;
	char *input = retrieve_input();
	char *path = _getenv();
	char **env_tokens = _tokenizer(path, ":");
	char **input_tokens = _tokenizer(input, " \t\n\r");

	pid_t child_pid = fork();

	cnt = 0;
	while (env_tokens[cnt] != NULL)
	{
		_realloc(env_tokens[cnt], _strlen(env_tokens[cnt]), _strlen(env_tokens[cnt])\
			       	+ _strlen(input_tokens[0]));

		pathname = _strcat(env_tokens[cnt], input_tokens[0]);
		if ((status = stat(pathname, buf)) == 0)
		{
			if (child_pid == 0)
			{
				execve(pathname, input_tokens, &path);
				perror("shell");
				exit (1);
			}
			else if(child_pid > 0)
			{
				int _status;
				do {
					waitpid(child_pid, &_status, WUNTRACED);
				} while (!WIFEXITED(_status) && !WIFSIGNALED(_status));
			}
			else
			{
				perror("shell");
			}
		}
		cnt++;
	}
}
