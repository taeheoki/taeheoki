/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:00:42 by taeheoki          #+#    #+#             */
/*   Updated: 2022/04/06 00:40:53 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct	s_node {
	int				data;
	struct s_node	*leftChild;
	struct s_node	*rightChild;
}	t_node;

t_node	*initNode(int data, t_node *leftChild, t_node *rightChild)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return (node);
}

void	preorder(t_node *root) // 전위 순회
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}

void	inorder(t_node *root) // 중위 순회
{
	if (root)
	{
		inorder(root->leftChild);
		printf("%d ", root->data);
		inorder(root->rightChild);
	}
}

void	postorder(t_node *root) // 후위 순회
{
	if (root)
	{
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d ", root->data);
	}
}

int	main(void)
{
	t_node *n7 = initNode(50, NULL, NULL);
	t_node *n6 = initNode(37, NULL, NULL);
	t_node *n5 = initNode(23, NULL, NULL);
	t_node *n4 = initNode(5, NULL, NULL);
	t_node *n3 = initNode(48, n6, n7);
	t_node *n2 = initNode(17, n4, n5);
	t_node *n1 = initNode(30, n2, n3);
	preorder(n1);
	printf("\n");
	inorder(n1);
	printf("\n");
	postorder(n1);
	printf("\n");
	system("pause");
	return (0);
}