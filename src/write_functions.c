#include "philo.h"

void	ft_write_state(t_philo *philo, int state, int miliseconds)
{
	if (ft_get_bool(&philo->dinner->mtx_end, &philo->dinner->end_dinner))
		return ;
	ft_mutex_lock(&philo->dinner->write);
	printf("%d: Philosopher %d", miliseconds, philo->philo_id);
	if (state == THINKING)
		printf(" is thinking... 💭\n");
	else if (state == EATING)
		printf(" is eating... 🍲\n");
	else if (state == SLEEPING)
		printf(" is sleeping... 💤\n");
	else if (state == FIRFORK || state == SECFORK)
		printf(" has taken a fork... 🥢\n");
	else if (state == DIED)
		printf(" has died... 💀\n");
	else
		printf("Error on getting philosopher state 🐛\n");
	// Debugging
	//printf("%d\n", philo->meal_counter);
	ft_mutex_unlock(&philo->dinner->write);
	return ;
}
