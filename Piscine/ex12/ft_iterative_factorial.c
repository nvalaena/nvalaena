int ft_iterative_factorial(int nb)
{
    int i;
    int result_nb;

    i = 1;
    result_nb = 1;
    if ((nb <= 0) || (nb >= 12))
    {
        return 0;
    }
    if (nb == 1)
        return 1;
    while (i <= nb)
    {
        result_nb = i * result_nb;
        i++;
    }
    return (result_nb);
}