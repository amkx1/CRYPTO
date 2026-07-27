#include <stdio.h>
#include <math.h>

int main()
{
    double x, y;

    printf("Enter two numbers: ");
    scanf("%lf %lf", &x, &y);

    if (x != (int)x || y != (int)y)
    {
        printf("GCD is defined only for integers.");
        return 0;
    }

    int a = (int)x;
    int b = (int)y;

    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    if (a == 0)
    {
        printf("GCD = %d", b);
        return 0;
    }

    if (b == 0)
    {
        printf("GCD = %d", a);
        return 0;
    }

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD = %d", a);

    return 0;
}