#include <stdio.h>
#include <math.h>

int main()
{
    double a, b;

    printf("Enter the dividend and divisor: ");
    scanf("%lf %lf", &a, &b);

    if (b == 0)
    {
        printf("No number should be divided by 0.");
    }
    else
    {
        double r = a - floor(a / b) * b;
        printf("%.2lf mod %.2lf = %.2lf", a, b, r);
    }

    return 0;
}