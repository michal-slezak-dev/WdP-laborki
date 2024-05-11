#include <stdio.h>
#include <string.h>

#define MAX_STR_LENGTH 200

int check_if_palindrome(char string[], int length);

int main() 
{
    char str[MAX_STR_LENGTH];
    printf("Podaj napis do sprawdzenia czy jest palindromem (bez spacji): ");
    fgets(str, MAX_STR_LENGTH, stdin);

    int str_len = strlen(str) - 1; // bez \0
    // printf("%s %d", str, str_len);
    printf("%d", check_if_palindrome(str, str_len));
    // printf("%c %c", str[0], str[str_len + 0 - 1]);

    return 0;
}

int check_if_palindrome(char string[], int length)
{   
    if (strlen(string) - 1 == 0) // sprawdzenie dla łańcucha pustego tylko, zgodnie z poleceniem
        return 0;

    for(int i = 0; i < length / 2; i++) // wystarczy do połowy
    {
        if(string[length - i - 1] != string[i])
            return 0;
    }
    return 1;
}