#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <stdbool.h>
#define MAX_SIZE (1000)

typedef unsigned long long	ull;

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

typedef enum	e_dir
{
	LEFT, 
	RIGHT, 
	ROOT
}				t_dir;

static double	probabilities[MAX_SIZE];
static double	opt[MAX_SIZE][MAX_SIZE];
static ull		optimal_k[MAX_SIZE][MAX_SIZE];

static void	get_probabilities(int argc, char **argv);
static void	solve(int node_cnt);
static void	print_result(int node_cnt);

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("usage: ./bst p1, p2, ... , pn");
		return (0);
	}
	get_probabilities(argc, argv);
	solve(argc - 1);
	print_result(argc - 1);
	system("leaks bst");
	return (0);
}

static double sum_of_probs(int i, int j)
{
	double res = 0.00;
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

static void get_probabilities(int argc, char **argv)
{
	for (int i = 1; i <= argc - 1; ++i)
		probabilities[i] = atof(argv[i]);	
}

static void solve(int node_cnt)
{
	for (int j = 0; j < node_cnt; ++j)
	{
		for (int i = 1; i + j <= node_cnt; ++i)
		{
			double	min_cost = LONG_MAX;
			int		min_k = 0;
			for (int k = i; k <= i + j; ++k)
			{
				double cost = 1.00 + get_prob_of_subtree(i, i + j, k, LEFT) * opt[i][k - 1] + get_prob_of_subtree(i, i + j, k, RIGHT) * opt[k + 1][i + j];
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
}

static void print_table_opt(int node_cnt)
{
	for (int i = 1; i <= node_cnt; ++i)
	{
		for (int j = 1; j <= node_cnt; ++j)
		{
			if (j >= i)
				printf("%5.2lf ", opt[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}
}

static void	print_table_k(int node_cnt)
{
	for (int i = 1; i <= node_cnt; ++i)
	{
		for (int j = 1; j <= node_cnt; ++j)
		{
			if (j >= i)
				printf("%5llu ", optimal_k[i][j]);
			else
				printf("      ");
		}
		printf("\n");
	}
}

static t_tree	*generate_tree(void)
{
	t_tree *new_tree = (t_tree *)malloc(sizeof(t_tree));
	new_tree->root = NULL;
	new_tree->height = -1;
	return (new_tree);
}

static t_node	*generate_node(int key)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->key = key;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

static void	fill_tree(t_tree *tree, int start, int end, t_node *parent, int depth)
{
	t_node	*cur_node;

	int k = optimal_k[start][end];
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

static void destory_nodes_recursive(t_node	*node)
{
	t_node	*left = node->left;
	t_node	*right = node->right;
	if (!node)
		return ;
	//if (!left && !right)
		//:return ;
	if (left)
		destory_nodes_recursive(left);
	if (right)
		destory_nodes_recursive(right);
	free(node);
}

static void destory_tree(t_tree *tr)
{
	if (!tr)
		return ;
	if (tr->root)
	{
		destory_nodes_recursive(tr->root);
		free(tr);
	}
}

static t_tree	*set_tree(int node_cnt)
{
	t_tree	*new_tree = generate_tree();
	fill_tree(new_tree, 1, node_cnt, NULL, 0);
	return (new_tree);
}

static int fill_tree_print_recursive(t_node *node, t_dir flag, int offset, int depth, char arr[20][300])
{
	char	cur_arr[30] = {0, };
	int 	width = 5;

	if (!node)
		return (0);
	sprintf(cur_arr, "<%03d>", node->key);
	int left = fill_tree_print_recursive(node->left, LEFT, offset, depth + 1, arr);
	int right = fill_tree_print_recursive(node->right, RIGHT, offset + left + width, depth + 1, arr);
	for (int i = 0; i < width; ++i)
		arr[depth][offset + left + i] = cur_arr[i];
	if (depth > 0 && flag == LEFT)
	{
		for (int i = 0; i < width + right; ++i)
			arr[depth - 1][offset + left + width / 2 + i] = '-';
		arr[depth - 1][offset + left + width / 2] = '+';
	}
	else if (depth > 0 && flag == RIGHT)
	{
		for (int i = 0; i < left + width; ++i)
			arr[depth - 1][offset - width / 2 + i] = '-';
		arr[depth - 1][offset + left + width / 2] = '+';
	}
	return (width + left + right);
}

static bool is_empty_line(char *str)
{
	for (int i = 0; str[i]; ++i)
	{
		if (!isspace(str[i]))
			return (false);
	}
	return (true);
}

static void print_tree(int node_cnt)
{
	char 	arr[20][300];
	t_tree	*tr;

	tr = set_tree(node_cnt);
	for (int i = 0; i < 20; ++i)
		sprintf(arr[i], "%80s", " ");
	fill_tree_print_recursive(tr->root, ROOT, 0, 0, arr);
	for (int i = 0; i < 20 && !is_empty_line(arr[i]); ++i)
		printf("%s\n", arr[i]);
	destory_tree(tr);
}

static void print_result(int node_cnt)
{
	printf("\ntable of opt[i,j]\n");
	print_table_opt(node_cnt);
	printf("\ntable of k[i,j]\n");
	print_table_k(node_cnt);
	printf("optimal binary search tree\n");
	print_tree(node_cnt);
	printf("\n");
}