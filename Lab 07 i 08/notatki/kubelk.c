#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    int* tabl = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        tabl[i] = rand() % 20;
    }

    int min = tabl[0], max = tabl[0];

    // Znalezienie wartości minimalnej i maksymalnej
    for (int i = 1; i < n; i++) {
        if (tabl[i] < min) {
            min = tabl[i];
        }
        if (tabl[i] > max) {
            max = tabl[i];
        }
    }

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", tabl[i]);
    printf("\n");

    int rozmiar_kubelki = max - min + 1;
    int* kubelki = (int*)calloc(rozmiar_kubelki, sizeof(int));

    // Rozdzielanie elementów do kubełków
    for (int i = 0; i < n; i++) {
        kubelki[tabl[i] - min]++;
    }

    printf("Bucket counts: ");
    for (int i = 0; i < rozmiar_kubelki; i++)
        printf("%d ", kubelki[i]);
    printf("\n");

    // Sortowanie i wypełnianie oryginalnej tablicy posortowanymi wartościami
    int index = 0;
    for (int i = 0; i < rozmiar_kubelki; i++) {
        while (kubelki[i] != 0) {
            tabl[index++] = i + min;// bo pod indeksem zero to liczba wystapien minimum elementu 
            kubelki[i]--;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", tabl[i]);
    printf("\n");

    free(tabl);
    free(kubelki);

    return 0;
}
