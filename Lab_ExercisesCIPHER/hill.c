#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a)
{
    int i;

    for (i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }

    return -1;
}

int main()
{
    char text[100];
    int key[2][2];
    int choice;
    int i, j;
    int a, b, c, d;
    int det, invDet;

    printf("Enter the 2x2 key matrix:\n");

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    getchar();

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    getchar();

    printf("\nEnter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    char clean[100];
    int len = 0;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            clean[len++] = toupper(text[i]);
        }
    }

    clean[len] = '\0';

    if (len % 2 != 0)
    {
        clean[len++] = 'X';
        clean[len] = '\0';
    }

    if (choice == 1)
    {
        // Encrypt

        printf("\nCiphertext: ");

        for (i = 0; i < len; i += 2)
        {
            a = clean[i] - 'A';
            b = clean[i + 1] - 'A';

            c = (key[0][0] * a + key[0][1] * b) % 26;
            d = (key[1][0] * a + key[1][1] * b) % 26;

            printf("%c%c", c + 'A', d + 'A');
        }
    }
    else if (choice == 2)
    {
        // Decrypt

        a = key[0][0];
        b = key[0][1];
        c = key[1][0];
        d = key[1][1];

        det = (a * d - b * c) % 26;

        if (det < 0)
            det += 26;

        invDet = modInverse(det);

        if (invDet == -1)
        {
            printf("\nInvalid key matrix!");
            printf("\nThe determinant has no inverse modulo 26.");
            return 0;
        }

        int inverse[2][2];

        inverse[0][0] = (d * invDet) % 26;
        inverse[0][1] = (-b * invDet) % 26;
        inverse[1][0] = (-c * invDet) % 26;
        inverse[1][1] = (a * invDet) % 26;

        printf("\nPlaintext: ");

        for (i = 0; i < len; i += 2)
        {
            a = clean[i] - 'A';
            b = clean[i + 1] - 'A';

            c = (inverse[0][0] * a +
                 inverse[0][1] * b) %
                26;

            d = (inverse[1][0] * a +
                 inverse[1][1] * b) %
                26;

            if (c < 0)
                c += 26;

            if (d < 0)
                d += 26;

            printf("%c%c", c + 'A', d + 'A');
        }
    }
    else
    {
        printf("\nInvalid choice!");
    }

    return 0;
}