#include <stdio.h>
int main()
{
    int a, b, ch;
    printf("Enter number 1: ");
    scanf("%d", &a);
    printf("Enter number 2: ");
    scanf("%d", &b);
    printf("Enter operation - 1-Addition\n2-Subtraction\n3-Multiplication\n4-Division\n5-Modulus: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("Sum: %d", a + b);
        break;
    case 2:
        printf("Difference: %d", a - b);
        break;
    case 3:
        printf("Product: %d", a * b);
        break;
    case 4:
        if (b == 0)
        {
            printf("No number can be divided by 0.");
        }
        else
        {
            printf("Quotient: %d", a / b);
        }
        break;
    case 5:
        printf("Remainder: %d", a % b);
        break;
    default:
        printf("Invalid input.");
    }

    return 0;
}