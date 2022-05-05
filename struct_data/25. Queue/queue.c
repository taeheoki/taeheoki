/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 15:52:30 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 16:55:50 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10000
#define INF 99999999

int	queue[SIZE];
int	front = 0;
int	rear = 0;

void	push(int data)
{
	if (rear >= SIZE)
	{
		printf("큐 오버플로우가 발생했습니다.\n");
		return;
	}
	queue[rear++] = data;
}

int		pop()
{
	if (front == rear)
	{
		printf("큐 언더플로우가 발생했습니다.\n");
		return (-INF);
	}
	return (queue[front++]);
}

void	show()
{
	printf("--- 큐의 앞 ---\n");
	for (int i = front; i < rear; i++)
		printf("%d\n", queue[i]);
	printf("--- 큐의 뒤 ---\n");
}

int		main(void)
{
	push(7);
	push(5);
	push(4);
	pop();
	push(6);
	pop();
	show();
	system("pause");
	return (0);
}