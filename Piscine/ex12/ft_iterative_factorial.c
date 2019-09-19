#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int i;
    int result_nb;

    if ((nb < 0) || (nb > 12))
        return (0);
    if ((nb == 0) || (nb == 1))
        return (1);
    result_nb = 1;
    while (nb > 1)
    {
        result_nb *= nb;
        nb--;
    }
    return (result_nb);
}

int main(void)
{
    printf("Factorial is %d\n", ft_iterative_factorial(12));
    return (0);
}