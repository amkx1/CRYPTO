#include <stdio.h>
#include <math.h>

int main()
{
    double input;
    int prime = 1;

    printf("Give a number: ");
    scanf("%lf", &input);

    if (input != (int)input)
    {
        printf("%.2lf is not an integer, so it cannot be a prime number.", input);
        return 0;
    }

    int a = (int)input;

    if (a < 2)
    {
        prime = 0;
    }
    else if (a == 2)
    {
        prime = 1;
    }
    else if (a % 2 == 0)
    {
        prime = 0;
    }
    else
    {
        for (int i = 3; i <= sqrt(a); i += 2)
        {
            if (a % i == 0)
            {
                prime = 0;
                break;
            }
        }
    }

    if (prime)
        printf("%d is a prime number.", a);
    else
        printf("%d is not a prime number.", a);

    return 0;
}