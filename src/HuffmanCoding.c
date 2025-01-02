#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../inc/HuffmanCoding.h"
#include "../inc/tools.h"

t_allNodes *newNodesArray(size_t capacity)
{
	t_allNodes *tmp = (t_allNodes *)malloc(sizeof(t_allNodes));

	tmp->size = 0;
	tmp->capacity = capacity;
	tmp->nodes = (t_node **)malloc((capacity + 1) * sizeof(t_node));

	return (tmp);
}

char *takeChars(char *str)
{
	size_t	i = -1;
	char	*tmp = (char *)malloc(1 * (sizeof(char)));
	
	while (str[++i])
		if (!isOnStr(tmp, str[i]))
			tmp = addChar(tmp, str[i]);
	
	return (tmp);
}

void	sortNodes(t_allNodes *allNodes)
{
	size_t	i;
	size_t	j = 0;
	t_node	*tmp;

	while (allNodes->nodes[j + 1])
	{
		i = 0;
		while (allNodes->nodes[i + 1])
		{
			if (allNodes->nodes[i]->freq > allNodes->nodes[i + 1]->freq)
			{
				tmp = allNodes->nodes[i];
				allNodes->nodes[i] = allNodes->nodes[i + 1];
				allNodes->nodes[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

t_allNodes *makeNodesArray(char *str)
{
	char		*chars = takeChars(str);
	size_t		capacity = strlen(chars);
	t_allNodes	*array = newNodesArray(capacity);
	size_t		i = -1;

	while (chars[++i])
	{
		array->nodes[i] = (t_node *)malloc(sizeof(t_node));
		array->nodes[i]->c = chars[i];
		array->nodes[i]->freq = getFreq(str, chars[i]);
	}
	array->nodes[i] = NULL;

	free(chars);
	sortNodes(array);
	return array;
}

int	main(void)
{
	char	*data = "AAAAAAAAAAAAAAABBBBBBBBCCCCDDE";
	size_t i = -1;
	t_allNodes *nodes = makeNodesArray(data);

	while (nodes->nodes[++i])
	{
		printf("Char:\t%c\n", nodes->nodes[i]->c);
		printf("Freq:\t%ld\n\n", nodes->nodes[i]->freq);
	}

	i = -1;
	while (nodes->nodes[++i])
		free(nodes->nodes[i]);

	free(nodes->nodes[i]);
	free(nodes->nodes);
	free(nodes);

	return (0);
}