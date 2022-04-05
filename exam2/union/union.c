/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taeheoki < taeheoki@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:51:36 by taeheoki          #+#    #+#             */
/*   Updated: 2022/03/28 22:14:39 by taeheoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;
	int	temp;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	write(1, &argv[1][i], 1);
	while (argv[1][i])
	{
		temp = i;
		while (--temp >= 0)
		{
			if (argv[1][temp] == argv[1][i])
				break ;
			if (temp == 0)
				write(1, &argv[1][i], 1);
		}
		++i;
	}
	j = 0;
	while (argv[2][j])
	{
		temp = j;
		len = i;
		while (--len >= 0)
		{
			if (argv[1][len] == argv[2][j])
			{
				temp = 0;
				break ;
			}
		}
		while (--temp >= 0)
		{
			if (argv[2][temp] == argv[2][j])
				break ;
			if (temp == 0)
				write(1, &argv[2][j], 1);
		}
		++j;
	}
	write(1, "\n", 1);
	return (0);
}