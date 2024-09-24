#include "philo.h"

int ft_check_good_input(int ac, char** av)
{
    if (ac != 5 && ac != 6)
        return (-1);

    int i = 1;
    while (i < ac)
    {
        if (!av[i][0] || !av[i])
            return (-4);

        // 2.147.483.647  10 chars max
        int len = ft_strlen(av[i]);
        if (len > 10)
            return (-2);

        // so digitos
        for (int j = 0; j < len; j++)
        {
            if (!ft_isdigit(av[i][j]) || ft_isdigit(av[i][j]) == '0')
                return (-3);
        }

        // 2.147.483.648 --> 9.999.999.999
        if (len == 10 && ft_strncmp(av[i], "2147483647", 10) > 0)
            return (-5);
        i++;
    }
    return 0;
}