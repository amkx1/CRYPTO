#include <stdio.h>
#include <string.h>

int main()
{
    int key;
    char str1[20], str2[20];

    printf("Enter a text: ");
    scanf("%s", str1);
    printf("Enter the key: ");
    scanf("%d", &key);

    int i;
    for (i = 0; i < strlen(str1); i++)
    {
        char ch = str1[i];

        if (ch >= 'a' && ch <= 'z')
        {
            int x = ch - 'a';
            x = (x + key) % 26;
            str2[i] = x + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            int x = ch - 'A';
            x = (x + key) % 26;
            str2[i] = x + 'A';
        }
        else
        {
            str2[i] = ch;
        }
    }

    printf("Encoded text: %s\n", str2);
    return 0;
}