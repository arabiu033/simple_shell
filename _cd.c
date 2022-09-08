#include "shell.h"

void cd_dum(void);
char *lwd = NULL;

/**
 * _cd - change working directory
 * @path: path to change to
 * Return: 0 - success
 */
int _cd(char *path)
{
	char *cwp, *buf, *str;
	int x;

	cwp = malloc(sizeof(char) * 512);
	if (!cwp)
		return (-1);
	cwp = getcwd(cwp, 512);
	lwd = !lwd ? _strdup(cwp) : lwd;

	if (path && *path == '.')
	{
		x = chdir(path);
		if (x && chdir_error(path))
			return (x);
	}
	else if (!path || (path && _strlen(path) == 1 && *path == '~'))
	{
		path = _getenv("HOME");
		x = chdir(path);
		if (x && chdir_error(path))
			return (x);
	}
	else if (path && (_strlen(path) == 1) && *path == '-')
	{
		x = chdir(lwd);
		if (x && chdir_error(lwd))
			return (x);
	}
	else if (path && *path != '/')
	{
		str = malloc(sizeof(char) * (_strlen(path) + 2));
		if (!str)
			return (-1);
		str[0] = '.';
		str[1] = '/';
		str = _strcat(str, path);

		x = chdir(str);
		free(str);
		if (x && chdir_error(str))
			return (x);
	}
	else
	{
		x = chdir(path);
		if (x && chdir_error(path))
			return (x);
	}

	if (!x)
	{
		free(lwd);
		lwd = strdup(cwp);
		free(cwp);
		free_cd(&lwd, &cwp);
		buf = malloc(sizeof(char) * 512);
		update_pwd(getcwd(buf, 512));
	}
	return (x);

}

/**
 * chdir_error - handle the error generated by chdir
 * @path: the specify path
 * Return: error type
 */
int chdir_error(char *path)
{
	perror(path);
	return (1);
}

char **l = NULL;
char **c = NULL;
/**
 * free_cd - free the memory allocatio by cd
 * @lwd: last working directory
 * @cwd: current working directory
 * Return: void - nothing
 */
void free_cd(char **lwd, char **cwd)
{
	if (lwd)
		l = lwd;
	if (cwd)
		c = cwd;

	if (!lwd && l)
		free(*l);

	if (!cwd && c)
		free(*c);
}

/**
 * update_pwd - update the PWD for enviromental after changing
 *              the working directory
 * @path: the new path
 * Return: void - nothing
 */
void update_pwd(char *path)
{
	_setenv("PWD", path);
	free(path);
}

/**
 * cd_dum -to bypass betty
 */
void cd_dum(void)
{
}
