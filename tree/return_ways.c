#include "tree.h"

int **return_short_ways(tab_of_integer *t)
{
    int count = 0;
    int **path = (int**)malloc(sizeof(int*));
    for (int i = 0; i < 100; i++)
        path[i] = (int*)malloc(sizeof(int));

    tab_of_integer *tab = t;
    for (; tab; tab = tab->next, count++);

    tab = t;
    if (count <= 2) {
        for (int i = 0; tab; tab = tab->next)
            for (int j = 0; j < tab->lenght; j++)
                path[i][j] = tab->integer[j];
    } else if (count > 2) {
        for (; t; t = t->next) {
            for (tab = t; tab; tab = tab->next) {
                if (tab->distance < t->distance)
                    tab->lenght = 1;
            }
        }
    }

    return path;
}