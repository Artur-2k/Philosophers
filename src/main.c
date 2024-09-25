#include "philo.h"

int		ft_start_dinner(t_dinner *dinner, int ac, char **av)
{
	// Dinner variables, forks, philos and monitor
	if (ft_init_dinner(ac, av, dinner))
		return (-1);

	// We reach here when all threads have been created and are
	// waiting for the are_sync bool to be turned true
	// Start the chronometer
	gettimeofday(&dinner->d_start, NULL);

	// Start the dinner
	ft_set_bool(&dinner->mutex, &dinner->are_sync, true);

	ft_monitoring(dinner);

	return (0);
}

int	main(int ac, char** av)
{
	t_dinner	dinner;
	int			n;

	// Returns a non 0 on error
	if (ft_check_good_input(ac, av))
		return (-1);

	// Initializes bools and ints and reads the conditions
	if (ft_start_dinner(&dinner, ac, av))
		return (-2);

	ft_join_threads(&dinner);
	ft_destroy_mutexes(&dinner);
	free(dinner.philos);
	free(dinner.forks);
	return (0);
}
