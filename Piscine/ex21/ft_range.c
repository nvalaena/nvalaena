#include <stdlib.h>

int *ft_range(int min, int max)
{
    int i;
    int *nmbrs;

    if (max < min)
        return (0);
    *nmbrs = (int*)malloc(sizeof(*nmbrs) * (max - min));
    i = 0;
    while (max > min)
    {
        nmbrs[i] = min;
        i++;
        min++;
    }
    return (nmbrs);
}