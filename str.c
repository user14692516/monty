#include "monty.h"
#include "lists.h"
/**
 * count_word - counting the number of words in a string
 * @s: string that is supposed to be evaluated.
 * Return: number of words
 */

int count_word(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}

/**
 * **strtow - splitting a string into words.
 * @str: string that is supposed to be split.
 * Return: pointer to an array of strings
 * Otherwise- NULL
 */

char **strtow(char *str)
{
	char **matrix, *tmp;
	int j, k = 0, len = 0, words, c = 0, start, end;

	len = strlen(str);
	words = count_word(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (j = 0; j <= len; j++)
	{
		if (isspace(str[j]) || str[j] == '\0' || str[j] == '\n')
		{
			if (c)
			{
				end = j;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = j;
	}

	matrix[k] = NULL;

	return (matrix);
}
/**
 * free_everything - freeing the arrays of strings
 * @args: array of strings to free
 */

void free_everything(char **args)
{
	int j;

	if (!args)
		return;
/*to be freed*/

	for (j = 0; args[j]; j++)
		free(args[j]);

	free(args);
}
