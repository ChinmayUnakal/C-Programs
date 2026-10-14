#include <stdio.h>
#include <stddef.h>

void *my_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *d = dest;
    const unsigned char *s = src;

    if (d < s)
    {
        // Copy forward
        for (size_t i = 0; i < n; i++)
        {
            d[i] = s[i];
        }
    }
    else if (d > s)
    {
        // Copy backward
        for (size_t i = n; i > 0; i--)
        {
            d[i - 1] = s[i - 1];
        }
    }

    return dest;
}

int main(void)
{
    char s[100] = "Chinmay";
    char t[100];

    // my_memmove(t, s, 8);
    // printf("%s\n", t);

    // my_memmove(s+2, s, 5);
    // printf("%s\n", s);

    my_memmove(s, s+2, 3);
    printf("%s\n", s);

    return 0;
}