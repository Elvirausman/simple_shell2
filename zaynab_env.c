#include "main.h"

/**
 * print_env - prints the current environment
 * @info: contains potential arguments, and maintain
 *          constant function prototype.
 * Return: Always 0
 */
int print_env(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * get_env - gets and remove the value of an environ variable
 * @info:  contains potential arguments, and maintain
 *          constant function prototype.
 * @var_name: environment variable name
 *
 * Return: the value
 */
char *get_env(info_t *info, const char *var_name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, var_name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * set_env - Initialize a new environment variable,
 *             or modify an existing one
 * @info:  contains potential arguments, and maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int set_env(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (set_env(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * unset_env - Remove an environment variable
 * @info:  contains potential arguments, and maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int unset_env(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		unset_env(info, info->argv[i]);

	return (0);
}

/**
 * env_list - populates environment linked list
 * @info: contains potential arguments, and maintain
 *          constant function prototype.
 * Return: Always 0
 */
int env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; env[i]; i++)
		add_node_end(&node, env[i], 0);
	info->env = node;
	return (0);
}
