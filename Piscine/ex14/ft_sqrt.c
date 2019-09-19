#include <stdio.h>

int ft_sqrt(int nb)
{
    int sqrt;
    int pol_nb;

    sqrt = 1;
    pol_nb = nb/2;
    if (nb < 0)
        return (0);
    if (nb == 0)
        return (0);
    while (sqrt * sqrt < pol_nb)
        ++sqrt;
    if ((nb * nb % sqrt) == 0)
        return (sqrt);
    else
        return (0);
}

int main(void)
{
    printf("Sqrt is %d\n", ft_sqrt(144));
    return 0;
}