#include <stdio.h>
int main()
{
    // printf("Hello, World!\n");
    int a;
    for(a = 0; a < 2000; a = a + 1 ){
        // printf("value of a: %d\n", a);
        a += 1;
    }
    printf("%d\n", a);
    return 0;
}