#include "philo.h"


 static void	ft_lock_forks(t_philo *philo)
{
	t_dinner *dinner;

	dinner = philo->dinner;
 	if (philo->philo_id % 2 == 0) //* Even lock r then l
	{
		ft_mutex_lock(philo->r_fork); //* First
		ft_write_state(philo, FIRFORK, ft_get_elapsed_time(dinner));

		ft_mutex_lock(philo->l_fork); //* Second
		ft_write_state(philo, SECFORK, ft_get_elapsed_time(dinner));
	}
	else //* Even lock l then r
	{
		ft_mutex_lock(philo->l_fork); //* First
		ft_write_state(philo, FIRFORK, ft_get_elapsed_time(dinner));

		ft_mutex_lock(philo->r_fork); //* Second
		ft_write_state(philo, SECFORK, ft_get_elapsed_time(dinner));
	} 
} 

static void	ft_eating(t_philo *philo)
{
	t_dinner *dinner;

	dinner = philo->dinner;
	if (ft_get_bool(&dinner->mtx_end, &dinner->end_dinner))
		return ;

	// Imposes an order wich they will grab forks
	ft_lock_forks(philo);
	
	//* Got both forks and now is eating
	ft_set_int(&philo->mutex, &philo->t_last_meal, ft_get_elapsed_time(dinner));
	ft_write_state(philo, EATING, ft_get_elapsed_time(dinner));

	//* Only if we need
	if (dinner->no_meals)
		(philo->meal_counter)++;

	ft_custom_sleep(dinner->t_eat * 1000);
		

	//* Leave the forks
	ft_mutex_unlock(philo->l_fork);
	ft_mutex_unlock(philo->r_fork);
}

static void	ft_sleeping(t_philo *philo)
{
	t_dinner *dinner;

	dinner = philo->dinner;
	ft_write_state(philo, SLEEPING, ft_get_elapsed_time(dinner));
	ft_custom_sleep(dinner->t_sleep * 1000);
}

static void	ft_thinking(t_philo *philo)
{
	t_dinner *dinner;

	dinner = philo->dinner;
	ft_write_state(philo, THINKING, ft_get_elapsed_time(dinner));
	//* Imposing a small sleep after thinking to avoid unfairness
	usleep(500);
}

void	*ft_dining(void *arg)
{
	t_philo	*philo;
	t_dinner *dinner;

	philo = (t_philo*)arg;
	dinner = philo->dinner;

	//* Sync all threads
	ft_sync_threads(philo->dinner);

	//* Delay even philosophers to avoid deadlocks
	if (philo->philo_id % 2 == 0)
		usleep(30000);

	//* Actual dinner
	while (ft_get_bool(&dinner->mtx_end, &dinner->end_dinner) == false)
	{
		//* Check if the philo is already full
		if (dinner->no_meals && philo->meal_counter == dinner->no_meals)
		{
			ft_set_bool(&philo->mutex, &philo->full, true);
			ft_increment_int(&dinner->mutex, &dinner->no_full);
			break ;
		}

		//! Eat
		ft_eating(philo);

		//! Sleep
		ft_sleeping(philo);

		//! Think
		ft_thinking(philo);
	}
	return (NULL);
}
