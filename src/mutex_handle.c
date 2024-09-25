#include "philo.h"

// Returns 0 on success and a non 0 on error
int	ft_mutex_init(pthread_mutex_t *mutex)
{
	int	ret_val;

	ret_val = pthread_mutex_init(mutex, NULL);
	if (ret_val)
		return (ret_val);
	return (0);
}

// Returns 0 on success and a non 0 on error
int	ft_mutex_destroy(pthread_mutex_t *mutex)
{
	int	ret_val;

	ret_val = pthread_mutex_destroy(mutex);
	if (ret_val)
		return (ret_val);
	return (0);
}

// Returns 0 on success and a non-zero value on error
int	ft_mutex_lock(pthread_mutex_t *mutex)
{
    int	ret_val;

    ret_val = pthread_mutex_lock(mutex);
    if (ret_val != 0)
        return (ret_val);
    return (0); // Success
}

// Returns 0 on success and a non-zero value on error
int	ft_mutex_unlock(pthread_mutex_t *mutex)
{
    int	ret_val;

    ret_val = pthread_mutex_unlock(mutex);
    if (ret_val != 0)
        return (ret_val);
    return (0); // Success
}
