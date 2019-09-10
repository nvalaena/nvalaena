#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}
int main(int ac, char **av)
{
    int i;

    i = 1;
    while (av[i])
    {
        ft_putstr(av[i]);
        ft_putchar('\n');
        i++;
    }
    return 0;
}