/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 00:08:10 by taeheoki          #+#    #+#             */
/*   Updated: 2021/12/24 01:43:02 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
	int	i;

	i = 5;
	while (i--)
	{
		printf("%d seconds left\n", i + 1);
		if (usleep(1000000) == -1)
			return (1);
	}
	return (0);
}