#include "philo.h"

void	*ft_monitoring(t_dinner	*dinner)
{
	t_philo		*philo;
	int			current_time;
	int			n;

	philo = dinner->philos;

	// Wait for the threads
	ft_sync_threads(dinner);

	// Monitoring for full philos and last meal times
	n = 0;
	while (!ft_get_bool(&dinner->mtx_end, &dinner->end_dinner))
	{
		if (dinner->no_meals != 0)
			if (ft_get_int(&dinner->mutex, &dinner->no_full) == dinner->no_philos)
				ft_set_bool(&dinner->mtx_end, &dinner->end_dinner, true);

		current_time = ft_get_elapsed_time(dinner);
		if (ft_get_bool(&philo[n].mutex, &philo[n].full) &&
			current_time - ft_get_int(&philo[n].mutex, &philo[n].t_last_meal) >= dinner->t_die)
		{
			ft_write_state(&philo[n], DIED, current_time);
			ft_set_bool(&dinner->mtx_end, &dinner->end_dinner, true);
		}
		n = (n + 1) % dinner->no_philos;
	}
	return (NULL);
}
