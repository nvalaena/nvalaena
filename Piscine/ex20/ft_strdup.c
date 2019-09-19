#include <stdlib.h>

char *ft_strdup(char *src)
{
    int i;
    int length;
    char *str;

    length = 0;
    while (src[length])
        length++;
    str = (char*)malloc(sizeof(*str) * (length + 1));
    i = 0;
    while (i < length)
    {
        str[i] = src[i];
        i++;
    }
    return (str);
}