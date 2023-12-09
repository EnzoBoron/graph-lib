#include "tree.h"

short compare_2_int(int *a, int *b, int lenght)
{
    for (int i = 0; i < lenght; i++) {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

short exist_in_tab_of_int(tab_of_integer *tab_int, int *path, int lengh)
{
    short exist = 0;

    if (tab_int == NULL)
        return 1;

    for (; tab_int; tab_int = tab_int->next) {
        if (tab_int->lenght == lengh + 1) {
            if (compare_2_int(tab_int->integer, path, lengh) == 1)
                return 0;
            else
                exist = 1;
        } else
            return 1;
    }

    return exist;
}

void find_all_possible_way(tab_of_integer **tab_int, tree *tmp, tree *destination, tree *head, int *path, int y, int n, double_array *square)
{
    if (tmp == NULL || tmp->display == 1 || *square->y == 25) {
        return;
    }

    path[n] = tmp->number;
    tmp->display = 1;
    y += tmp->distance;

    if (tmp == destination) {
        if (!exist_in_tab_of_int((*tab_int), path, n) == 0)
            (*tab_int) = create_node_int((*tab_int), path, n + 1, y);
        if (*square->y < 24) {
            tmp = head;
            // printf("reset tmp %d\n", tmp->number);
            tmp->display = 1;
            change_all_variable_display(&tmp, 0, square->array, 0);
            //printf("%d\n", tmp->s[0]->s[0]->display);
            (*square->y)++;
            find_all_possible_way(tab_int, tmp, destination, head, path, y, 0, square);
        }
    } else {
        for (int x = 0; x < 4; x++) {
            int next_node_index = square->array[*square->y][x] - 1;
            find_all_possible_way(tab_int, tmp->s[next_node_index], destination, head, path, y, n + 1, square);
        }

    }
}
