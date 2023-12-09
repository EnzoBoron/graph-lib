#include "tree.h"

void free_linked_list(tab_of_integer **list)
{
    if (list == NULL || *list == NULL)
        return;

    tab_of_integer *rem = *list;

   for (; rem; rem = rem->next);
   free(rem);

    free_linked_list(&rem);
}

short have_children(tree *root)
{
    short have = 0;

    for (int i = 0; i < 10; i++)
        if (root->s[i] != NULL)
            have++;

    return have;
}

void free_tree(tree **root, short choice)
{
    // 1: free the node without child/children
    // 2: free a random node
    // 3: free the circle of nodes
}

void free_binary_tree(tree *root)
{
    // If the node haven't children/child; free node
}

int **get_path(void)
{
    tree *root = NULL;
    tree *save = NULL;
    tab_of_integer **tab_int = (tab_of_integer**)malloc(sizeof(tab_of_integer*));
    if (!tab_int)
        exit(0);
    position pos = { 5, 6 };
    // if (pos.pos > pos.dest) {
    //     int tmp = pos.pos;
    //     pos.pos = pos.dest;
    //     pos.dest = tmp;
    // }

    tree *destination;
    int *path, *n, *y;

    double_array *square = malloc(sizeof(double_array));
    if (!square)
        exit (999);
    square->array = (int**)malloc(100 * sizeof(int*));
    if (!square->array)
        exit (55);
    for (int i = 0; i < 30; i++) {
        square->array[i] = (int*)malloc(10 * sizeof(int));
        if (!square->array[i])
            exit (66);
    }
    square->y = malloc(sizeof(int));
    if (!square->y)
        exit (88);
    int tmp_tab[300] = {1, 2, 3, 4, 1, 2, 4, 3, 1, 3, 2, 4, 3, 4, 2, 1, 4, 2, 3, 1, 4, 3, 2, 2, 1, 3, 4, 2, 1, 4, 3, 2, 3, 1, 4, 2, 3, 4, 1, 2, 4, 1, 3, 2, 4, 3, 1, 3, 1, 2, 4, 3, 1, 4, 2, 3, 2, 1, 4, 3, 2, 4, 1, 3, 4, 1, 2, 3, 4, 2, 1, 4, 1, 2, 3, 4, 1, 3, 2, 4, 2, 1, 3, 4, 2, 3, 1, 4, 3, 1, 2, 4, 3, 2, 1};
    int t = 0;
    for (int j = 0; j != 24; j++)
        for (int i = 0; i != 4 ;i++) {
        square->array[j][i] = tmp_tab[t++];
    }
    y = (int*)malloc(sizeof(int));
    if (!y)
        exit (90);
    *y = 0;
    // Allocate memory for each row

    // for (int j = 0; j != 24; j++) {
    //     printf("%d ", j);
    //     for (int i = 0; i != 4 ;i++) {
    //         printf("%d", square->array[j][i]);
    //     }
    // printf("\n");
    // }

    root = create_root_node(1);
    root = add_connection(root, 2, 3);
    root = add_connection(root, 3, 2);
    root->s[0] = add_connection(root->s[0], 4, 1);
    root->s[0] = add_connection(root->s[0], 5, 2);
    root->s[1] = add_connection(root->s[1], 6, 5);
    connecte_together(&root->s[1]->s[0], &root->s[0]->s[0], 4.0);
    // printf("test = %d\n", root->s[0]->s[0]->s[0]->s[3]->s[3]->number);
    // return;
    destination = root;
    path = malloc(sizeof(int) * 300);
     if (!path)
        exit(87);
    n = malloc(sizeof(int)); *n = 0;
    if (!n)
        exit(39);
    // y = malloc(sizeof(int*)); *y = 0;

    adapte_position_about_root(root, &root, pos.pos);
    root->display = 1;
    change_all_variable_display(&root, 0, square->array, 0);

    find_destination_position(root, &destination, pos.dest, square);
    root->display = 1;
    change_all_variable_display(&root, 0, square->array, 0);
    save = root;
    // find_all_possible_way_interative(tab_int, root, destination);
    // printf("test = %d\n", root->s[3]->s[3]->s[0]->s[1]->number);
    find_all_possible_way(tab_int, root, destination, save, path, 0, 0, square);
    // return;
    // display_tree(root);
    // return;
    display_list_int((*tab_int));
    int **way = (int**)malloc(sizeof(int*));
    for (int i = 0; i < 100; i++)
        way[i] = (int*)malloc(sizeof(int));
    way = return_short_ways((*tab_int));

    // // free_all();
    //     // free binary tree
    //     // free tree
    free_linked_list(tab_int);
    // // free_tree(&root, 0); segfault
    // free(path);
    free(n);
    return way;
}