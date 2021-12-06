/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:30 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 17:08:04 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct s_node {
	int				data;
	struct s_node	*next;
} t_node;

typedef struct s_queue {
	t_node	*front;
	t_node	*rear;
	int		count;
} t_queue;

void	push(t_queue *queue, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	node->next = NULL;
	if (queue->count == 0)
		queue->front = node;
	else
		queue->rear->next = node;
	queue->rear = node;
	queue->count++;
}

int		pop(t_queue *queue)
{
	t_node	*node;
	int		data;

	if (queue->count == 0)
	{
		printf("큐 언더플로우가 발생했습니다.\n");
		return (-INF);
	}
	node = queue->front;
	data = node->data;
	queue->front = node->next;
	free(node);
	queue->count--;
	return (data);
}

void	show(t_queue *queue)
{
	t_node	*cur;
	
	cur = queue->front;
	printf("--- 큐의 앞 ---\n");
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	printf("--- 큐의 뒤 ---\n");
}

int		main(void)
{
	t_queue	queue;

	queue.front = queue.rear = NULL;
	queue.count = 0;
	push(&queue, 7);
	push(&queue, 5);
	push(&queue, 4);
	pop(&queue);
	push(&queue, 6);
	pop(&queue);
	show(&queue);
	system("pause");
	return (0);
}