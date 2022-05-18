#include "shell.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * *nbr_spaces - return the number of occurent of a string
 * @s: string to check
 * Return: int
 */

unsigned int nbr_spaces(char *s)
{
	int i, cmpt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i]  == ' ')
			cmpt++;
	}

	return (cmpt);
}


/**
 *stringToTokens - split a sentence into multiple words.
 *@str: the string passed as argument.
 *Return: tokens
 */
char **stringToTokens(char *str)
{
	int i = 0;
	char **tokens = (char **)malloc(sizeof(char **) * BUFSIZ);
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, " ");

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}