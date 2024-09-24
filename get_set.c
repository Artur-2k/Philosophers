#include "philo.h"

int	ft_set_bool(pthread_mutex_t *mutex, bool *target, bool value)
{
	ft_mutex_lock(mutex);
	*target = value;
	ft_mutex_unlock(mutex);
	return (0);
}

bool	ft_get_bool(pthread_mutex_t *mutex, bool *target)
{
	bool	ret_val;

	ft_mutex_lock(mutex);
	ret_val = *target;
	ft_mutex_unlock(mutex);
	return (ret_val);
}

void	ft_set_int(pthread_mutex_t *mutex, int *target, int value)
{
	ft_mutex_lock(mutex);
	*target = value;
	ft_mutex_unlock(mutex);
	return ;
}

int	ft_get_int(pthread_mutex_t *mutex, int *target)
{
	int	ret_val;

	ft_mutex_lock(mutex);
	ret_val = *target;
	ft_mutex_unlock(mutex);
	return (ret_val);
}

void	ft_increment_int(pthread_mutex_t *mutex, int *target)
{
	ft_mutex_lock(mutex);
	++(*target);
	ft_mutex_unlock(mutex);
	return ;
}