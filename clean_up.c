#include "philo.h"

int	ft_join_threads(t_dinner *dinner)
{
	int	n;

	n = 0;
	while (n < dinner->no_philos)
	{
		if (ft_thread_join(dinner->philos[n].thread))
			printf("Error joining thread %d\n", n + 1);
		n++;
	}
	return (0);
}

int	ft_destroy_mutexes(t_dinner *dinner)
{
	int	n;

	if (ft_mutex_destroy(&dinner->mutex))
		printf("Mutex of dinner not destroyed\n");
	n = 0;
	while (n < dinner->no_philos)
	{
		if (ft_mutex_destroy(&dinner->philos[n].mutex))
			printf("Mutex of thread %d not destroyed\n", n + 1);
		n++;
	}
	n = 0;
	while (n < dinner->no_philos)
	{
		if (ft_mutex_destroy(&dinner->forks[n]))
			printf("Mutex of fork %d not destroyed\n", n + 1);
		n++;
	}
	return (0);
}