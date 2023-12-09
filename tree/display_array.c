#include <stdio.h>

void display_array_int(int *tab, int size)
{
    for (int i = 0; i != size; i++)
        printf("%d ", tab[i]);
    printf("\n");
}