#ifndef _TREE_H_
#define _TREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define true 1
#define false 0
#define NUMBER_OF_CHILDREN 3
#define NUMBER_OF_PARENT 1

typedef struct binary_tree {
    float distance;
    struct binary_tree *left;
    struct binary_tree *right;
} binary_tree;

typedef struct double_array {
    int *x;
    int *y;
    int **array;
} double_array;

typedef struct position {
    int pos;
    int dest;
} position;

typedef struct tab_of_integer {
    float distance;
    int *integer;
    int lenght;
    short display;
    short is_little;
    struct tab_of_integer *next;
} tab_of_integer;

typedef struct tree {
    float distance;
    int number;
    short display;
    short registe;
    struct tree *parent;
    struct tree *s[NUMBER_OF_CHILDREN];
} tree;

void erreur_malloc(const char *message, int exit_code);

void verify_ptr_avaible_following(tree **t, tree *add, float distance);
tree *create_root_node(int num);
tree *add_connection(tree *t, int num1, float distance);
void connecte_together(tree **root1, tree **root2, float distance);

void display_tree(tree *t);

void find_all_possible_way(tab_of_integer **tab_int, tree *tmp, tree *destination, tree *head, int *path, int y, int n, double_array *squar);
void change_all_variable_display(tree **t, int value, int **map, int y);

void display_array_int(int *tab, int size);

tab_of_integer *create_node_int(tab_of_integer *tab, int *array, int lenght, float distance);

void display_list_int(tab_of_integer *tab_int);

void add_connection_parent(tree **t, tree *add);
void put_all_ptr_at_null(tree **t);

void adapte_position_about_root(tree *t, tree **head, int num);
void find_destination_position(tree *root, tree **head, int dest, double_array *square);

int **get_path(void);

int **return_short_ways(tab_of_integer *t);

short compare_2_int(int *a, int *b, int lenght);

#endif