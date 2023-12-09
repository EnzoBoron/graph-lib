#include "tree.h"

tab_of_integer *create_node_int(tab_of_integer *tab, int *array, int lenght, float distance)
{
    tab_of_integer *node = (tab_of_integer*)malloc(sizeof(tab_of_integer));
    if (!node)
        erreur_malloc("Error creating node in create_node_int", 4);

    node->is_little = 0;
    node->distance = distance;
    node->display = false;
    node->lenght = lenght;
    node->integer = (int*)malloc(sizeof(int) * (lenght));
    for (int i = 0; i != lenght; i++) {
        node->integer[i] = array[i];
        // printf("%d", node->integer[i]);
    }
    // printf("\n");
    node->next = NULL;

    if (tab)
        node->next = tab;

    return node;
}