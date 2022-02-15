/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:00:42 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 20:03:03 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
	int				data;
	struct t_node	*leftChild;
	struct t_node	*rightChild;
} t_node;

t_node	*initNode(int data, t_node *leftChild, t_node *rightChild)
{
	t_node *node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->leftChild = leftChild;
	node->rightChild = rightChild;
	return (node);
}