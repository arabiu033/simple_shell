#include "shell.h"

/**
 * _cd - change working directory
 * @path: path to change to
 * Return: 0 - success
 */
int _cd(char *path)
{
	char *cwp;
	static char *pwd;

	cwp = malloc(sizeof(char) * 512);
	cwp = getcwwd(cwp, 512);

	if (*path == '.')
		chdir(path);
	if ((_strlen(path) == 1 && *path == '~') || !path)
		chdir(_getenv("HOME"));
	if ((_strlen(path) == 1) && *path == '-')
		chdir(pwd);
	if (path && *path != '/')
	{
		str = malloc(sizeof(char) * (_strlen(path) + 2));
		str[0] = '.';
		str[1] = '/';
		str = _strcat(str, path);
		chdir(str);
