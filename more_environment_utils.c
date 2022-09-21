#include "shell.h"

/**
 * add_environment - adds a new variable to the environment
 * @name: name of the environment variable
 * @value: value of the environment variable
 *
 * Return: the new environment
 */
char **add_environment(char *name, char *value)
{
	int old_len, new_len, len, a, i;
	char **environ_cpy;

	environ_cpy = _malloc2D(environ);
	for (old_len = 1; environ[old_len]; old_len++)
		;
	new_len = old_len + 1;
	environ_cpy = _realloc(environ_cpy, old_len * sizeof(char *), (new_len) * sizeof(char *));
	if (!environ_cpy)
		return (NULL);

	environ_cpy[old_len] = NULL;
	len = _strlen(name) + _strlen(value) + 2;
	environ_cpy[old_len - 1] = malloc(len * sizeof(char));
	if (!environ_cpy[old_len - 1])
		return (NULL);

	for (a = 0; name[a]; a++)
		environ_cpy[old_len - 1][a] = name[a];
	environ_cpy[old_len - 1][a] = '=';
	a++;
	for (i = 0; value[i]; i++, a++)
		environ_cpy[old_len - 1][a] = value[i];
	environ_cpy[old_len - 1][a] = '\0';
	return (environ_cpy);
}

/**
 * remove_environment - removes avariable from the environment
 * @rmv: index of the variable to remove
 *
 * Return: the new environment
 */
char **remove_environment(int rmv)
{
	int len, j = 0, k = 0, x, i, n;
	char **new_environ;

	for (len = 0; environ[len]; len++)
		;
	new_environ = malloc(sizeof(char *) * len);
	if (!new_environ)
		return (NULL);

	new_environ[len - 1] = NULL;
	while (j < len)
	{
		if (j != rmv)
		{
			n = _strlen(environ[j]);
			new_environ[k] = malloc(sizeof(char) * (n + 1));
			if (!new_environ[k])
			{
				for (x = 0; x < k; x++)
					free(new_environ[x]);
				free(new_environ[len - 1]);
				free(new_environ);
				return (NULL);
			}
			for (i = 0; environ[j][i]; i++)
				new_environ[k][i] = environ[j][i];
			new_environ[k][i] = '\0';
			k++;
		}
		j++;
	}

	return (new_environ);
}
