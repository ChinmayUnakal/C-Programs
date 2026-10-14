#include <stdio.h>

void *my_memcpy( void *dest, const void *src, size_t n )
{
    void *start = dest;

    unsigned char *d = dest;
    const unsigned char *s = src;

    for( size_t i = 0; i < n; i++ )
    {
        *d++ = *s++;
    }

    return start;
}

int main()
{
    int s[10] =  { 1, 2, 3, 4, 5 } ;
    int d[10];

    my_memcpy( d, s, 2 * sizeof(int) );

    for( int i = 0; i<2; i++ )
    {
        printf( " %d ", d[i] );
    }

}