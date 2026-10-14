#include <stdio.h>

//This works too...
// int my_strcmp(const char *c, const char *d)
// {
//     while (*c == *d)
//     {
//         if (*c == '\0')
//         {
//             return 0;
//         }

//         c++;
//         d++;
//     }

//     return *c - *d;
// }

//More cleaner version...
int my_strcmp(const char *c, const char *d)
{
    while (*c && *c == *d)
    {
        c++;
        d++;
    }

    return (unsigned char)*c - (unsigned char)*d;
}

int main(void)
{
    const char *a = "Chinmay";
    const char *b = "Chinmay";

    if (my_strcmp(a, b) != 0)
    {
        printf("The strings a and b are not same\n");
    }
    else
    {
        printf("The strings a and b are same!!!\n");
    }

    return 0;
}