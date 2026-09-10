#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void createMatrix(char key[])
{
    int used[26] = {0};
    int row = 0, col = 0;
    int i, j;

    used['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++)
    {
        char ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A'])
        {
            matrix[row][col++] = ch;
            used[ch - 'A'] = 1;

            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (!used[i])
        {
            matrix[row][col++] = 'A' + i;
            used[i] = 1;

            if (col == 5)
            {
                col = 0;
                row++;
            }
        }
    }
}

void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void prepareText(char text[], char prepared[])
{
    int i = 0, j = 0;
    char a, b;

    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            a = toupper(text[i]);

            if (a == 'J')
                a = 'I';

            i++;

            while (text[i] != '\0' && !isalpha(text[i]))
                i++;

            if (text[i] == '\0')
            {
                prepared[j++] = a;
                prepared[j++] = 'X';
            }
            else
            {
                b = toupper(text[i]);

                if (b == 'J')
                    b = 'I';

                if (a == b)
                {
                    prepared[j++] = a;
                    prepared[j++] = 'X';
                }
                else
                {
                    prepared[j++] = a;
                    prepared[j++] = b;
                    i++;
                }
            }
        }
        else
        {
            i++;
        }
    }

    prepared[j] = '\0';
}

void encrypt(char text[], char result[])
{
    int i, r1, c1, r2, c2;

    for (i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            result[i] = matrix[r1][(c1 + 1) % 5];
            result[i + 1] = matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            result[i] = matrix[(r1 + 1) % 5][c1];
            result[i + 1] = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            result[i] = matrix[r1][c2];
            result[i + 1] = matrix[r2][c1];
        }
    }

    result[i] = '\0';
}

void decrypt(char text[], char result[])
{
    int i, r1, c1, r2, c2;

    for (i = 0; text[i] != '\0'; i += 2)
    {
        findPosition(text[i], &r1, &c1);
        findPosition(text[i + 1], &r2, &c2);

        if (r1 == r2)
        {
            result[i] = matrix[r1][(c1 + 4) % 5];
            result[i + 1] = matrix[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2)
        {
            result[i] = matrix[(r1 + 4) % 5][c1];
            result[i + 1] = matrix[(r2 + 4) % 5][c2];
        }
        else
        {
            result[i] = matrix[r1][c2];
            result[i + 1] = matrix[r2][c1];
        }
    }

    result[i] = '\0';
}

int main()
{
    char key[100];
    char plaintext[200];
    char prepared[200];
    char encrypted[200];
    char decrypted[200];

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    createMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    prepareText(plaintext, prepared);

    encrypt(prepared, encrypted);
    decrypt(encrypted, decrypted);

    printf("\nPrepared Text : %s", prepared);
    printf("\nEncrypted Text: %s", encrypted);
    printf("\nDecrypted Text: %s\n", decrypted);

    return 0;
}