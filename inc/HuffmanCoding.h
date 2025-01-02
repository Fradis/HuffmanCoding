#ifndef HUFFMANCODING_H
# define HUFFMANCODING_H

typedef struct s_node
{
	char			c;
	size_t			freq;
	struct s_node	*left;
	struct s_node	*right;
} t_node;

typedef struct s_allNodes
{
	size_t		size;
	size_t		capacity;
	t_node		**nodes;
} t_allNodes;

#endif
