#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[100], key[100];
    int choice, i, j = 0, shift;

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = '\0';

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            shift = toupper(key[j % strlen(key)]) - 'A';

            if (choice == 1)
                text[i] = ((toupper(text[i]) - 'A' + shift) % 26) + 'A';

            else if (choice == 2)
                text[i] = ((toupper(text[i]) - 'A' - shift + 26) % 26) + 'A';

            j++;
        }
    }

    if (choice == 1)
        printf("\nEncrypted text: %s", text);

    else if (choice == 2)
        printf("\nDecrypted text: %s", text);

    else
        printf("\nInvalid choice!");

    return 0;
}
