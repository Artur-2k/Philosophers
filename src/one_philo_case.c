#include "philo.h"

void	*ft_one_philo_case(void *arg)
{
	t_philo	*philo;
	t_dinner *dinner;

	philo = (t_philo*)arg;
	dinner = philo->dinner;

	// Sync all threads
	ft_sync_threads(philo->dinner);

    if (dinner->no_philos == 1)
	{
		ft_mutex_lock(philo->l_fork); // Lock the only fork
		ft_write_state(philo, FIRFORK, ft_get_elapsed_time(dinner));

		// Simulate thinking, since the philosopher can't eat with one fork
		ft_custom_sleep(dinner->t_die * 1000); 

		// Release the fork
		ft_mutex_unlock(philo->l_fork);
	}
	return (NULL);
}
