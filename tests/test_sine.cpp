#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main ()
{
    double deg, sinx, cosx;
    deg = 30;
    sinx = sin(deg*PI/180);
    cosx = cos(deg*PI/180);
    printf("Deg: %f, sin: %f, cos: %f \n", deg, sinx, cosx);
    return 0;
}