/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:14 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 14:46:12 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct s_node {
	int			data;
	struct s_node		*next;
} t_node;

typedef struct s_stack{
	t_node	*top;
} t_stack;

void	push(t_stack *stack, int data)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = stack->top;
	stack->top = node;
}

int		pop(t_stack *stack)
{
	t_node	*node;
	int		data;

	if (stack->top == NULL)
	{
		printf("스택 언더플로우가 발생했습니다.\n");
		return (-INF);
	}
	node = stack->top;
	data = node->data;
	stack->top = node->next;
	free(node);
	return (data);
}

void	show(t_stack *stack)
{
	t_node	*cur;

	cur = stack->top;
	printf("--- 스택의 최상단 ---\n");
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 스택의 최하단 ---\n");
}

int main(void)
{
	t_stack	s;

	s.top = NULL;
	push(&s, 7);
	push(&s, 5);
	push(&s, 4);
	pop(&s);
	push(&s, 6);
	pop(&s);
	show(&s);
	system("pause");
	return (0);
}