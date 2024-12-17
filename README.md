# Philosophers

In this project, we are tasked with solving the classic **Dining Philosophers Problem** to better understand threads, synchronization, and concurrency issues, as well as the dangers of race conditions and deadlocks.

![Demo](assets/demo.gif)

## Description

The Dining Philosophers Problem is a well-known problem in computer science. It describes a scenario where **n** philosophers sit around a table, each with their own plate of spaghetti. Between each pair of philosophers, there is one fork, and a philosopher needs two forks (the one on their left and the one on their right) to eat. Philosophers alternate between thinking, eating, and sleeping.

The challenge is to design a solution where:

1. Philosophers avoid starvation.
2. Deadlocks do not occur.
3. The program runs efficiently and fairly.

In this implementation:

- Even philosophers are delayed slightly to avoid deadlocks.
    
- Philosophers sleep for a small period to allow fairness when others are waiting for forks.


## Getting Started

### Installing

1. **Clone the Repository**  
   Download the project by running:  
   
        git clone https://github.com/Artur-2k/Philosophers
   

2. **Navigate to the Project Directory**

        cd Philosophers/

3. **Compile the Program**

    Build the project by running:

        make all

### The arguments

To run the program, pass the following arguments:

```
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_meals]
```

- `number_of_philosophers`: The total number of philosophers (max: 200).
- `time_to_die`: Time (in milliseconds) a philosopher can survive without eating. (max: 60ms)
- `time_to_eat`: Time (in milliseconds) a philosopher takes to eat. (max: 60ms)
- `time_to_sleep`: Time (in milliseconds) a philosopher sleeps after eating. (max: 60ms)
- `number_of_meals` (optional): Number of meals each philosopher must eat before stopping.

### Example Execution

Run the program with 4 philosophers, where the time to die, eat, and sleep are 800 ms, 200 ms, and 200 ms respectively, and each philosopher must eat 5 meals:

```
./philo 4 800 200 200 5
```

Output will show the behavior of the philosophers (thinking, eating, sleeping) and indicate if a philosopher dies under certain conditions.

## Author

Contributor name and contact info

Artur Carvalho: [Github](https://github.com/Artur-2k)
