#include <stdio.h>

// This works too...
// char *my_strcpy(char *dest, const char *src)
// {
//     char *start = dest;

//     do {
//         *dest++ = *src++;
//     } while (*src != '\0');

//     *dest = '\0';

//     return start;
// }

// More cleaner function...
char *my_strcpy(char *dest, const char *src)
{
    char *start = dest;

    while ((*dest++ = *src++) != '\0')
        ;

    return start;
}

int main(void)
{
    char *n = "Chinmay";
    char c[10];

    printf("copied into c[] > %s\n", my_strcpy(c, n));
    printf("size = %zu\n", sizeof(c));
}