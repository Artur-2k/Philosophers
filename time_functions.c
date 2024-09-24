#include "philo.h"

// CPU effiecient precise usleep
// Uses usleep for the bulk and loops for sleeps <1ms
void	ft_custom_sleep(long usec)
{
	struct timeval	start, end;
	long			elapsed;

	// bad input check
	if (usec <= 0)
		return ;

	//fills the start.tv_sec and start.tv_usec
	gettimeofday(&start, NULL);

	// uses the system call to sleep for the bulk
	if (usec > 1000)
		usleep (usec - 1000);

	gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) * 100000 + (end.tv_usec - start.tv_usec);
    while (elapsed < usec)
	{
		gettimeofday(&end, NULL);
    	elapsed = (end.tv_sec - start.tv_sec) * 100000 + (end.tv_usec - start.tv_usec);
	}

	return ;
}

int		ft_get_elapsed_time(t_dinner *dinner)
{
	long	elapsed_sec;
	long	elapsed_usec;

	gettimeofday(&dinner->d_current, NULL);
	elapsed_sec = dinner->d_current.tv_sec - dinner->d_start.tv_sec;
	elapsed_usec = dinner->d_current.tv_usec - dinner->d_start.tv_usec;

	return ((int)(elapsed_sec * 1000 + elapsed_usec / 1000));
}
