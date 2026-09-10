#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char message[100];
    int key, choice;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    key = key % 26;

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    for (int i = 0; message[i] != '\0'; i++)
    {

        if (isupper(message[i]))
        {
            if (choice == 1)
                message[i] = (message[i] - 'A' + key) % 26 + 'A';
            else if (choice == 2)
                message[i] = (message[i] - 'A' - key + 26) % 26 + 'A';
        }

        else if (islower(message[i]))
        {
            if (choice == 1)
                message[i] = (message[i] - 'a' + key) % 26 + 'a';
            else if (choice == 2)
                message[i] = (message[i] - 'a' - key + 26) % 26 + 'a';
        }
    }

    if (choice == 1)
        printf("\nEncrypted Text: %s", message);
    else if (choice == 2)
        printf("\nDecrypted Text: %s", message);
    else
        printf("\nInvalid choice!");

    return 0;
}