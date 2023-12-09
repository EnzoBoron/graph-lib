#include "tree.h"

int number_of_children(tree *t)
{
    int count = 0;

    for (int i = 0; i < 10; i++)
        if (t->s[i] != NULL)
            count++;

    return count;
}

void display_tree(tree *t)
{
    if (t == NULL || t->display == 1)
        return;

    printf("%d(%d) ", t->number, number_of_children(t));
    t->display = 1;

    for (int i = 0; i < 10; i++)
        if (t->s[i] && t->s[i]->display != 1)
            display_tree(t->s[i]);
}