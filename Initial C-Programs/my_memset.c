#include <stdio.h>

void *my_memset(void *s, int c, size_t n)
{
    unsigned char *t = s;
    
    for ( size_t i = 0; i < n; i++  )
    {
        t[i] = c;
    }

    return s;
}

int main()
{
    char p[10];
    my_memset( p, 0xFF, 10 );
     for (size_t i = 0; i < 10; i++)
    {
        printf("%u ", (unsigned char)p[i]);
    }

}