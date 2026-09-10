#include <stdio.h>
#include <string.h>

void encrypt(char text[], int rails)
{
    int len = strlen(text);
    char rail[rails][len];

    int i, j, row = 0, direction = 1;

    // Initialize the rail matrix
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Place characters in zigzag pattern
    for (i = 0; i < len; i++)
    {
        rail[row][i] = text[i];

        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    // Read row by row
    printf("Ciphertext: ");

    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] != '\n')
                printf("%c", rail[i][j]);
        }
    }

    printf("\n");
}

void decrypt(char cipher[], int rails)
{
    int len = strlen(cipher);
    char rail[rails][len];

    int i, j, row = 0, direction = 1;
    int index = 0;

    // Initialize the rail matrix
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    // Mark the zigzag positions
    for (i = 0; i < len; i++)
    {
        rail[row][i] = '*';

        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    // Fill the marked positions with ciphertext
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] == '*' && index < len)
            {
                rail[i][j] = cipher[index++];
            }
        }
    }

    // Read the zigzag pattern
    row = 0;
    direction = 1;

    printf("Plaintext: ");

    for (i = 0; i < len; i++)
    {
        printf("%c", rail[row][i]);

        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }

    printf("\n");
}

int main()
{
    char text[100];
    int rails, choice;

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    if (rails < 2)
    {
        printf("Number of rails must be at least 2.\n");
        return 0;
    }

    if (choice == 1)
        encrypt(text, rails);
    else if (choice == 2)
        decrypt(text, rails);
    else
        printf("Invalid choice.\n");

    return 0;
}