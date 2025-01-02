#include "../inc/HuffmanCoding.h"

//Make, allocate and return a new t_allNodes struct to save an array
//and number of t_nodes structs
t_allNodes *newNodesArray(size_t capacity)
{
	t_allNodes *tmp = (t_allNodes *)malloc(sizeof(t_allNodes));

	tmp->size = 0;
	tmp->capacity = capacity;
	tmp->nodes = (t_node **)malloc((capacity + 1) * sizeof(t_node));

	return (tmp);
}

//Return a allocated string with the diferents characters used in the
//original string
char *takeChars(char *str)
{
	size_t	i = -1;
	char	*tmp = (char *)malloc(1 * (sizeof(char)));
	
	while (str[++i])
		if (!isOnStr(tmp, str[i]))
			tmp = addChar(tmp, str[i]);
	
	return (tmp);
}

//Fuction to sort by repetition order, from lowest to highest,
//the t_nodes array con t_nodes struct
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


//Return de t_allNodes struct, filled with t_nodes array, counted
//and sorted, given the original string
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

//Begin of the Huffman Coding develop
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