#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

// Libraries
#include <stdio.h> // for testing
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h> // -pthread
#include <stdbool.h>
#include <stdarg.h>

// States
typedef enum e_states
{
	THINKING = 0,
	EATING = 1,
	SLEEPING = 2,
	FIRFORK = 3,
	SECFORK = 4,
	FULL = 5,
	DIED = 6
}	t_states;

// Structures
typedef struct s_dinner t_dinner;
typedef struct	s_philo t_philo;

struct	s_philo
{
	// Identifiers
	int				philo_id;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;

	// Philo info
	pthread_mutex_t	mutex;
	int				meal_counter;
	int				t_last_meal;
	bool			full;

	// Dinner pointer
	t_dinner 		*dinner;
};

struct s_dinner
{
	// Conditions
	int				no_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				no_meals;

	// Philosophers array
	t_philo			*philos;

	// Forks array
	pthread_mutex_t	*forks;

	// Data race prevention
	pthread_mutex_t mtx_end;
	pthread_mutex_t	mutex;
	pthread_mutex_t write;

	// Sync
	bool			are_sync;

	// Monitor
	int				no_full;
	bool			end_dinner;

	// Dinner time
	struct timeval	d_start;
	struct timeval	d_current;

};

// Prototypes
// Parsing input
int		ft_check_good_input(int ac, char** av);

// Write functions
void	ft_write_state(t_philo *philo, int state, int miliseconds);
// Initialization
int		ft_init_dinner(int ac, char **av, t_dinner *dinner);

// Monitoring
void	*ft_monitoring(t_dinner	*dinner);

// Dinner
void	*ft_dining(void *arg);
void	*ft_one_philo_case(void *arg);

// Syncro
void	ft_sync_threads(t_dinner *dinner);

// Time functions
int		ft_get_elapsed_time(t_dinner *dinner);
void	ft_custom_sleep(long usec);

// Gets & Sets
bool	ft_get_bool(pthread_mutex_t *mutex, bool *target);
int		ft_get_int(pthread_mutex_t *mutex, int *target);
int		ft_set_bool(pthread_mutex_t *mutex, bool *target, bool value);
void	ft_set_int(pthread_mutex_t *mutex, int *target, int value);
void	ft_increment_int(pthread_mutex_t *mutex, int *target);

// Clean up
int		ft_join_threads(t_dinner *dinner);
int		ft_destroy_mutexes(t_dinner *dinner);

// Utils
int		ft_strncmp(const char *str1, const char *str2, size_t n);
int		ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

// Thread and mutex handle
int		ft_thread_create(pthread_t *thread, void *(*routine)(void *), void *arg);
int		ft_thread_join(pthread_t thread);
int		ft_mutex_init(pthread_mutex_t *mutex);
int		ft_mutex_destroy(pthread_mutex_t *mutex);
int		ft_mutex_lock(pthread_mutex_t *mutex);
int		ft_mutex_unlock(pthread_mutex_t *mutex);

#endif