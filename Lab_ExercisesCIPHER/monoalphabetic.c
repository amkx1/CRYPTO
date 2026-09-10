#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100];
    char ciphertext[100];
    char decrypted[100];

    char plainAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char cipherAlphabet[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i, j;

    printf("Enter your message: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = '\0';

    for (i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = toupper(plaintext[i]);

        if (ch >= 'A' && ch <= 'Z')
        {
            ciphertext[i] = cipherAlphabet[ch - 'A'];
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    ciphertext[i] = '\0';

    printf("\nEncrypted Text: %s\n", ciphertext);

    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        char ch = ciphertext[i];

        if (ch >= 'A' && ch <= 'Z')
        {
            for (j = 0; j < 26; j++)
            {
                if (cipherAlphabet[j] == ch)
                {
                    decrypted[i] = plainAlphabet[j];
                    break;
                }
            }
        }
        else
        {
            decrypted[i] = ciphertext[i];
        }
    }

    decrypted[i] = '\0';

    printf("Decrypted Text: %s\n", decrypted);

    return 0;
}