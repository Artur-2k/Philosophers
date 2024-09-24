#include "philo.h"

// Spinlock until all threads are created and ready
// Busy waiting
void	ft_sync_threads(t_dinner *dinner)
{
	while (ft_get_bool(&dinner->mutex, &dinner->are_sync) == false)
		;
}
