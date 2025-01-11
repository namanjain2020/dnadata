#include <stdio.h>
#include <ctype.h>
#include <string.h>

void printBinary(char ch) 
{
    for (int i = 7; i >= 0; i--) 
    {
        printf("%d", (ch >> i) & 1);
    }
}

void printDNA(char ch) 
{
    for (int i = 7; i >= 1; i -= 2) 
    {
        int b1 = (ch >> i) & 1;
        int b2 = (ch >> (i - 1)) & 1;
        if (b1 == 0 && b2 == 0) 
        {
            printf("T");
        } 
        else if (b1 == 1 && b2 == 1) 
        {
            printf("A");
        } 
        else if (b1 == 0 && b2 == 1) 
        {
            printf("C");
        } 
        else 
        {
            printf("G");
        }
    }
}

int main() 
{
    char str[100];
    printf("Enter your name: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    for (int i = 0; str[i]; i++) 
    {
        str[i] = toupper(str[i]);
    }

    printf("Your name in uppercase: %s\n", str);

    printf("The binary code for your name is: ");
    for (int i = 0; str[i]; i++) 
    {
        printBinary(str[i]);
    }
    printf("\n");

    printf("The DNA sequence for your name is: ");
    for (int i = 0; str[i]; i++) 
    {
        printDNA(str[i]);
    }
    printf("\n");

    return 0;
}
