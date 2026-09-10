#include <stdio.h>
#include <string.h>
#include <ctype.h>

void columnarEncrypt(char text[], char key[], char result[])
{
    int len = strlen(text);
    int cols = strlen(key);
    int rows = (len + cols - 1) / cols;

    char matrix[100][100];
    int i, j, k = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (k < len)
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }

    k = 0;

    for (int num = 1; num <= cols; num++)
    {
        for (j = 0; j < cols; j++)
        {
            if (key[j] - '0' == num)
            {
                for (i = 0; i < rows; i++)
                    result[k++] = matrix[i][j];
            }
        }
    }

    result[k] = '\0';
}

void columnarDecrypt(char text[], char key[], char result[])
{
    int len = strlen(text);
    int cols = strlen(key);
    int rows = (len + cols - 1) / cols;

    char matrix[100][100];
    int i, j, k = 0;

    for (int num = 1; num <= cols; num++)
    {
        for (j = 0; j < cols; j++)
        {
            if (key[j] - '0' == num)
            {
                for (i = 0; i < rows; i++)
                    matrix[i][j] = text[k++];
            }
        }
    }

    k = 0;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            result[k++] = matrix[i][j];
    }

    result[k] = '\0';
}

int main()
{
    char plaintext[100];
    char key1[20], key2[20];
    char first[100], ciphertext[100];
    char decrypted1[100], decrypted2[100];

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';

    int p = 0;
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (!isspace(plaintext[i]))
            plaintext[p++] = toupper(plaintext[i]);
    }
    plaintext[p] = '\0';

    printf("Enter first key: ");
    scanf("%s", key1);

    printf("Enter second key: ");
    scanf("%s", key2);

    columnarEncrypt(plaintext, key1, first);
    columnarEncrypt(first, key2, ciphertext);
    printf("\nAfter first transposition: %s", first);
    printf("\nCiphertext: %s\n", ciphertext);
    columnarDecrypt(ciphertext, key2, decrypted1);
    columnarDecrypt(decrypted1, key1, decrypted2);

    printf("\nDecrypted text: %s\n", decrypted2);

    return 0;
}