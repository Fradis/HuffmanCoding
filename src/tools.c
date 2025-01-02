#include "../inc/tools.h"

//Given a string, add a new char, freeing the original
//and allocating the new one
char	*addChar(char *str, char c)
{
	size_t size = strlen(str) + 2;
	char *tmp = (char *)malloc(size * (sizeof(char)));

	size_t i = 0;

	while (i < strlen(str))
	{
		tmp[i] = str[i];
		i++;
	}

	tmp[i++] = c;
	tmp[i] = '\0';

	free(str);
	return (tmp);
}

//Simple fuction to check if a char is on a string
bool	isOnStr(char *str, char c)
{
	size_t i = 0;

	while (str[i])
		if (str[i++] == c)
			return (true);
	return (false);
}

//Simple function to count the number of repetitions
//in a string
size_t	getFreq(char *str, char c)
{
	size_t i = -1;
	size_t ret = 0;

	while (str[++i])
		if (str[i] == c)
			ret++;
	
	return (ret);
}