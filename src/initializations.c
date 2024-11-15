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

static void	ft_init_philo_vars(t_dinner *dinner, int n)
{
	dinner->philos[n].full = false;
	dinner->philos[n].philo_id = n + 1;
	dinner->philos[n].meal_counter = 0;
	dinner->philos[n].t_last_meal = 0;
	dinner->philos[n].dinner = dinner;
	dinner->philos[n].l_fork = &dinner->forks[n];
	dinner->philos[n].r_fork = &dinner->forks[(n + 1) % dinner->no_philos];
}

static void	ft_clear_mutexes_error(int n, t_dinner *dinner)
{
	while (n >= 0)
	{
		if (ft_mutex_destroy(&dinner->philos[n].mutex))
			printf("Mutex of thread %d not destroyed\n", n + 1);
		n--;
	}
}

static void	ft_join_threads_error(int n, t_dinner *dinner)
{
	while (n >= 0)
	{
		if (ft_thread_join(dinner->philos[n].thread))
			printf("Error joining thread %d\n", n + 1);
		n--;
	}
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
			return (free(dinner->philos), ft_clear_mutexes_error(n, dinner), -1);
		if (dinner->no_philos == 1)
		{
			if (ft_thread_create(&dinner->philos[n].thread, ft_one_philo_case, (void*)&dinner->philos[n]))
				return (free(dinner->philos), ft_join_threads_error(n, dinner), -2);
		}
		else
			if (ft_thread_create(&dinner->philos[n].thread, ft_dining, (void*)&dinner->philos[n]))
				return (free(dinner->philos), ft_join_threads_error(n, dinner), -3);
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
	if (ft_init_philo_vars)
		return (-1);
	if (ft_mutex_init(&dinner->mtx_end))
		return (-2);
	if (ft_mutex_init(&dinner->mutex))
		return (-3);
	if (ft_mutex_init(&dinner->write))
		return (-4);
	if (ft_init_forks(dinner))
		return (-5);
	if (ft_init_philos(dinner))
		return (-6);
	return (0);
}
