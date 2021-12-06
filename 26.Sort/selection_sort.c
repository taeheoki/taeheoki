/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:25:59 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 17:41:32 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 1000


int	a[SIZE];

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	main(void)
{
	int	n;
	int	min;
	int	index;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
	{
		min = INT_MAX;
		for (int j = i; j < n; j++)
		{
			if (min > a[j])
			{
				min = a[j];
				index = j;
			}
		}
		swap(&a[i], &a[index]);
	}
	for (int i = 0; i < n; i++)
		printf("%d ",a[i]);
	system("pause");
	return (0);
}