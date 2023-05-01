#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <vector>
#include <queue>
#define MAX_SIZE (1000)
#define COMPACT (1)

typedef unsigned long long	ull;

static double	probabilities[MAX_SIZE];
static double	opt[MAX_SIZE][MAX_SIZE];
static ull		optimal_k[MAX_SIZE][MAX_SIZE];
static char		arr[20][255];
static char		tree_printable[15][300];

typedef struct	s_node
{
	int				key;
	struct s_node	*left;
	struct s_node	*right;
}				t_node;

typedef struct	s_tree
{
	t_node	*root;
	int		height;
}				t_tree;

enum e_dir
{
	LEFT, RIGHT, ROOT
};

static double sum_of_probs(int i, int j)
{
	double	res;

	res = 0.00;
	while (i <= j)
		res += probabilities[i++];
	return (res);
}

static double get_prob_of_subtree(int i, int j, int k, enum e_dir flag)
{
	if (flag == LEFT)
		return (sum_of_probs(i, k - 1) / sum_of_probs(i, j));
	else
		return (sum_of_probs(k + 1, j) / sum_of_probs(i , j));
}

static t_tree	*generate_tree(void)
{
	t_tree	*new_tree;

	new_tree = (t_tree *)malloc(sizeof(t_tree));
	new_tree->root = NULL;
	new_tree->height = -1;
	return (new_tree);
}

static t_node	*generate_node(int key)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

static void	fill_tree(t_tree *tree, int start, int end, t_node *parent, int depth)
{
	int k;
	t_node	*cur_node;

	k = optimal_k[start][end];
	if (start > end)
		return ;
	if (k == 0)
		return ;
	if (tree->height < depth)
		tree->height = depth;
	if (tree->root == NULL)
	{
		cur_node = generate_node(k);
		tree->root = cur_node;
	}
	else
	{
		cur_node = parent;
	}
	if (optimal_k[start][k - 1])
	{
		cur_node->left = generate_node(optimal_k[start][k - 1]);
		fill_tree(tree, start, k - 1, cur_node->left, depth + 1);
	}
	if (optimal_k[k + 1][end])
	{
		cur_node->right = generate_node(optimal_k[k + 1][end]);
		fill_tree(tree, k + 1, end, cur_node->right, depth + 1);
	}
}
/*
static int print_tree_recursive(t_node *node, int depth, int offset, enum e_dir flag)
{
	char b[20];
	int	 width = 5;

	if (!node)
		return (0);
	sprintf(b, "(%03d)", node->key);
	int left = print_tree_recursive(node->left, depth + 1, offset, LEFT);
	int	right = print_tree_recursive(node->right, depth + 1, offset + left + width, RIGHT);
	for (int i = 0; i < width; ++i)
		arr[depth][offset + left + i] = b[i];
	if (depth && flag == LEFT)
	{
		for (int i = 0; i < width + right; ++i)
			arr[depth - 1][offset + left + width / 2 + i] = '_';
		arr[depth - 1][offset + left + width / 2] = '.';
	}
	else if (depth && flag == RIGHT)
	{
		for (int i = 0; i < left + width; ++i)
			arr[depth - 1][offset - width / 2 + i] = '_';
		arr[depth - 1][offset + left + width / 2] = '.';
	}
	return (left + width + right);
}

static void print_tree(t_tree *tr)
{
	for (int i = 0; i < 20; ++i)
		sprintf(arr[i], "%80s", " ");
	print_tree_recursive(tr->root, 0, 0, RIGHT);
	for (int i = 0; i < 10; ++i)
		printf("%s\n", arr[i]);
}


static int print_recursive2(t_node *node, int depth, int offset, enum e_dir flag)
{
	char	cur_str[20];
	int		width;
	int 	left;
	int		right;
	int		i;

	if (!node)
		return (0);
	width = 5;
	sprintf(cur_str, "<%03d>", node->key);
	left = print_recursive2(node->left, depth + 1, offset, LEFT);
	right = print_recursive2(node->right, depth + 1, offset + left + width, RIGHT);
	for (i = 0; i < width; ++i)
		tree_printable[depth][offset + left + i] = cur_str[i];
	if (depth > 0 && flag == LEFT)
	{
		for (i = 0; i < width + right; ++i)
			tree_printable[depth - 1][offset + left + width / 2 + i] = '-';
		tree_printable[depth - 1][offset + left + width / 2] = '*';
	}
	else if (depth > 0 && flag == RIGHT)
	{
		for (i = 0; i < left + width; ++i)
			tree_printable[depth - 1][offset - width / 2 + i] = '-';
		tree_printable[depth - 1][offset + left + width / 2] = '*';
	}
	return (width + left + right);	
}

static void print_tree2(t_tree *tr)
{
	int	i;

	for (i = 0; i < 20; ++i)
		sprintf(tree_printable[i], "%80s", " ");
	print_recursive2(tr->root, 0, 0, LEFT);
	for (i = 0; i < 10; ++i)
		printf("%s\n", tree_printable[i]);
}
*/


int main(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	int		min_k;
	int 	node_cnt;
	double	cost;
	double	min_cost;
	t_tree	*tr;
	char	s[20][255];

	if (argc < 2)
	{
		printf("usage: ./bst p1, p2, ... , pn");
		return (0);
	}
	node_cnt = argc - 1;
	for (i = 1; i <= node_cnt; ++i)
		probabilities[i] = atof(argv[i]);	
	for (j = 0; j < node_cnt; ++j)
	{
		for (i = 1; i + j <= node_cnt; ++i)
		{
			min_cost = LONG_MAX;
			for (k = i; k <= i + j; ++k)
			{
				cost = 1.00 + get_prob_of_subtree(i, i + j, k, LEFT) * opt[i][k - 1] + get_prob_of_subtree(i, i + j, k, RIGHT) * opt[k + 1][i + j];
				if (cost < min_cost)
				{
					min_k = k;
					min_cost = cost;
				}
			}
			opt[i][i + j] = min_cost;
			optimal_k[i][i + j] = min_k;
		}
	}
	printf("\n**********table of opt[i,j]**********\n");
	for (i = 1; i <= node_cnt; ++i)
	{
		for (j = 1; j <= node_cnt; ++j)
		{
			if (j >= i)
				printf("%5.2lf ", opt[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}	
	printf("\n*************************************\n");
	printf("\n***********table of k[i,j]***********\n");
	for (i = 1; i <= node_cnt; ++i)
	{
		for (j = 1; j <= node_cnt; ++j)
		{
			if (j >= i)
				printf("%5llu ", optimal_k[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}
	printf("\n*************************************\n");
	printf("*********optimal binary search tree*********\n");
	tr = generate_tree();
	fill_tree(tr, 1, node_cnt, NULL, 0);
	printf("\n********************************************\n");
	
	return (0);
}
