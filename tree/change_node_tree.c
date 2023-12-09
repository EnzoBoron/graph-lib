#include "tree.h"

void adapte_position_about_root(tree *t, tree **head, int num)
{
    if (t == NULL || t->display == 1)
        return;

    if (t->number == num) {
        (*head) = t;
        return;
    }

    t->display = 1;

    for (int i = 0; i != 4; i++)
        adapte_position_about_root(t->s[i], head, num);

    return;
}

void find_destination_position(tree *root, tree **head, int dest, double_array *square)
{
    if (root == NULL || root->display == 1 )
        return;

    if (root->number == dest) {
        (*head) = root;
        return;
    }

    root->display = 1;

    for (int x = 0; x < 4; x++) {
        find_destination_position(root->s[x], head, dest, square);
    }
}


void change_all_variable_display(tree **t, int value, int **map, int y)
{
    if (*t == NULL || y == 24)
        return;

    (*t)->display = value;

    for (int x = 0; x < 4; x++) {
        int next_node_index = map[y][x] - 1;
        if (next_node_index >= 0 && next_node_index < 4) {
            change_all_variable_display(&((*t)->s[next_node_index]), value, map, y + 1);
        }
    }

    return;
}
