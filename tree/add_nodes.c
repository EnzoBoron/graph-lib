#include "tree.h"

void verify_ptr_avaible_following(tree **t, tree *add, float distance)
{
    for (int i = 0; i != NUMBER_OF_CHILDREN; i++) {
        if ((*t)->s[i] == NULL) {
            (*t)->s[i] = add;
            (*t)->s[i]->distance = distance;
            return;
        }
    }
}

// void verify_ptr_avaible_connection(tree **t, tree *add, float distance)
// {
//     for (int i = 3; i != 6; i++) {
//         if ((*t)->s[i] == NULL) {
//             (*t)->s[i] = add;
//             (*t)->s[i]->distance = distance;
//             return;
//         }
//     }
// }

void add_connection_parent(tree **t, tree *add)
{
    if ((*t) == NULL) {
        dprintf(2, "tree is null (add_connection_parent)\n");
        return;
    }
    if ((*t)->s[3] == NULL)
        (*t)->s[3] = add;
    else {
        dprintf(2, "Pointeur number %d full!(parent)\n", (*t)->number);
        exit(2);
    }
}

void put_all_ptr_at_null(tree **t)
{
    for (int i = 0; i != (NUMBER_OF_CHILDREN + NUMBER_OF_PARENT); i++)
        (*t)->s[i] = NULL;
}

tree *add_connection(tree *t, int num1, float distance)
{
    if (t == NULL){
        printf("ERROR: tree == NULL with num1 %d distance %f", num1, distance);
    }
    tree *node = (tree *)malloc(sizeof(tree));
    if (node == NULL) {
        erreur_malloc("Malloc add_connection failed\n", 1);
    }

    node->number = num1;
    node->distance = distance;
    node->display = 0;
    put_all_ptr_at_null(&node);
    verify_ptr_avaible_following(&t, node, distance);
    add_connection_parent(&node, t);

    return t;
}

tree *create_root_node(int num)
{
    tree *root = (tree*)malloc(sizeof(tree));
    if (!root)
        erreur_malloc("malloc: create_root_node", 3);
    root->number = num;
    root->distance = 0;
    root->display = 0;
    put_all_ptr_at_null(&root);

    return root;
}

void connecte_together(tree **root1, tree **root2, float distance)
{
    verify_ptr_avaible_following(root1, (*root2), distance);
    verify_ptr_avaible_following(root2, (*root1), distance);
}