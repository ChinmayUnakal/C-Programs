#include <stdio.h>

int my_strlen( char *p )
{
    //int count = 0; 
    char *start = p;

    while( *(p) != '\0' )
    {
        p++;
        //count++;
    }
    
    return p - start;
    //return count;
}

int main()
{

   char *s = "Chinmay";

   printf( " The length of string %s is : %d ", s, my_strlen(s) );

}