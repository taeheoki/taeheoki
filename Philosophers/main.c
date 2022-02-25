#include <stdio.h>
#include <stdlib.h>

typedef struct s_info
{
	int			num_of_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			must_eat_cnt;
	int			cnt_full;
	int			end;
	long long	first_timestamp;
}				t_info;

typedef struct s_philo
{
	int			tid;
	int			left_fork;
	int			right_fork;
	int			cnt_eat;
	long long	cur;
	long long	last_meal;
	t_info		*info;
}				t_philo;

void	test(t_info *info)
{
	info->end = 1;
}

int main(void)
{
	t_info	info;
	t_philo	*philo;
	int i;

	info = (t_info){0, };
	philo = (t_philo *)malloc(sizeof(t_philo) * 5);
	i = 0;
	while (i < 5)
	{
		philo[i].info = &info;
		i++;
	}
	test(&info);
	printf("end : %d\n", philo[0].info->end);
	return (0);
}