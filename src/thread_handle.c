#include "philo.h"

// Returns 0 on success and a non 0 on error
int	ft_thread_create(pthread_t *thread, void *(*routine)(void *), void *arg)
{
	int ret_val;

	ret_val = pthread_create(thread, NULL, routine, arg);
	if (ret_val) // Error
		return (ret_val); // Error no
	return (0); // Success
}

// Returns 0 on success and a non 0 on error
int	ft_thread_join(pthread_t thread)
{
	int	ret_val;

	ret_val = pthread_join(thread, NULL);
	if (ret_val)
		return (ret_val);
	return (0); // Success
}



