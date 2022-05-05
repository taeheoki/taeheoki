/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_cal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:07:14 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 15:51:45 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node {
	int				data[100];
	struct s_node	*next;
} t_node;

typedef struct s_stack{
	t_node	*top;
} t_stack;

void	push(t_stack *stack, char *data)
{
	t_node	*node;
	
	node = (t_node *)malloc(sizeof(t_node));
	strcpy(node->data, data);
	node->next = stack->top;
	stack->top = node;
}

char	*getTop(t_stack *stack)
{
	t_node *top;

	top = stack->top;
	return (top->data);
}

char	*pop(t_stack *stack)
{
	t_node	*node;
	char	*data;

	if (stack->top == NULL)
	{
		printf("스택 언더플로우가 발생했습니다.\n");
		return (NULL);
	}
	node = stack->top;
	strcpy(data, node->data);
	stack->top = node->next;
	free(node);
	return (data);
}

int		getPriority(char *i)
{
	if (!strcmp(i, "("))
		return (0);
	if (!strcmp(i, "+") || !strcmp(i, "-"))
		return (1);
	if (!strcmp(i, "*") || !strcmp(i, "/"))
		return (2);
	return (3);
}

char	*transition(t_stack, char **s, int size)
{
	char	res[1000];
	int		i;

	res = "";
	for(i = 0; i < size; i++)
	{
		if (!strcmp)
	}
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