#include "philo.h"



static int		ft_init_forks(t_dinner *dinner)
{
	pthread_mutex_t *forks;
	int	n;

	forks = (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)
					* dinner->no_philos);
	if (!forks)
		return (-1);
	dinner->forks = forks;
	n = 0;
	while (n < dinner->no_philos)
	{
		if (ft_mutex_init(&dinner->forks[n]))
			return (n);
		n++;
	}
	return (0);
}


static int	ft_init_philos(t_dinner *dinner)
{
	int	n;

	dinner->philos = (t_philo *)malloc(sizeof(t_philo) * dinner->no_philos);
	if (dinner->philos == NULL)
		return (-1);
	n = 0;
	while (n < dinner->no_philos) // assing forks
	{
		dinner->philos[n].full = false;
		dinner->philos[n].philo_id = n + 1;
		dinner->philos[n].meal_counter = 0;
		dinner->philos[n].t_last_meal = 0;
		dinner->philos[n].dinner = dinner;
		dinner->philos[n].l_fork = &dinner->forks[n];
		dinner->philos[n].r_fork = &dinner->forks[(n + 1) % dinner->no_philos];

		if (ft_mutex_init(&dinner->philos[n].mutex))
			return (free(dinner->philos), -1);
		if (dinner->no_philos == 1)
		{
			if (ft_thread_create(&dinner->philos[n].thread, ft_one_philo_case, (void*)&dinner->philos[n]))
				return (free(dinner->philos), -2);
		}
		else
			if (ft_thread_create(&dinner->philos[n].thread, ft_dining, (void*)&dinner->philos[n]))
				return (free(dinner->philos), -3);
		n++;
	}
	return (0); // Success
}

int		ft_init_dinner(int ac, char **av, t_dinner *dinner)
{
	dinner->are_sync = false;
	dinner->end_dinner = false;
	dinner->no_full = 0;
	dinner->no_philos = ft_atoi(av[1]);
	dinner->t_die = ft_atoi(av[2]);
	dinner->t_eat = ft_atoi(av[3]);
	dinner->t_sleep = ft_atoi(av[4]);
	if (ac == 6)
		dinner->no_meals = ft_atoi(av[5]);
	else
		dinner->no_meals = 0;
	if (ft_mutex_init(&dinner->mtx_end))
		return (-1);
	if (ft_mutex_init(&dinner->mutex))
		return (-2);
	if (ft_mutex_init(&dinner->write))
		return (-3);
	if (ft_init_forks(dinner))
		return (-4);
	if (ft_init_philos(dinner))
		return (-5);
	return (0);
}
