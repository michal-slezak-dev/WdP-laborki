#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

void mem_alloc_err(int* arr);
int* letter_count(char string[], int length, int num_of_letters);

int main()
{
    /* U mnie funkcja3 to funkcja letter_count*/
    int num_of_letters = 26; // można też wsm o ile się nie mylę #define zrobić
    char string[MAX_SIZE];

    printf("Podaj lancuch znakow: ");
    fgets(string, MAX_SIZE, stdin); 
    // printf("%d", strlen(string));

    // występowanie liter a-z
    int* letter_occurrence_arr = letter_count(string, strlen(string), num_of_letters);
    printf("Krotnosc wystepowania liter a-z w podanych lancuchu znakow: %s\n", string);
    for(int i = 0; i < num_of_letters; i++)
    {
        printf("%c: %d\n", (char)i + 97, letter_occurrence_arr[i]);
    }


    free(letter_occurrence_arr);
    letter_occurrence_arr = NULL;

    return 0;
}

void mem_alloc_err(int* arr)
{
    if(arr == NULL)
    {
        printf("Nie udalo sie zaalokowac pamieci :-(");
        exit(1);
    }
}

int* letter_count(char string[], int length, int num_of_letters)
{   
    int* letter_occurrence_arr = (int*)calloc(num_of_letters, sizeof(int));
    mem_alloc_err(letter_occurrence_arr);
    // małe litery ASCII od 97 do 122 kody
    for(int i = 0; string[i] != '\0'; i++) // można też zamiast środkowego dać i < length
    {   
        if(isalpha(string[i]) && islower(string[i]))
        letter_occurrence_arr[((int)string[i]) - 97]++;
    }

    return letter_occurrence_arr;
}