/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:25:30 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/06 19:16:29 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000

int	a[SIZE];

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	quickSort(int start, int end)
{
	if (start >= end)
		return;
	int key = start, i = start + 1, j = end;
	while (i <= j) // 엇갈릴 때까지 반복합니다.
	{
		while (i <= end && a[i] <= a[key])
			i++;
		while (j > start && a[j] >= a[key])
			j--;
		if (i > j)
			swap(&a[key], &a[j]);
		else
			swap(&a[i], &a[j]);
	}
	quickSort(start, j - 1);
	quickSort(j + 1, end);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	system("pause");
	return (0);
}