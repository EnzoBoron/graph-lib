#include "tree.h"

void display_list_int(tab_of_integer *tab_int)
{
    if (tab_int == NULL) {
        printf("END\n");
        return;
    }

    for (int i = 0; i != tab_int->lenght; i++) {
        printf("%d -> ", tab_int->integer[i]);
    }
    printf(" NULL %fm\n", tab_int->distance);

    display_list_int(tab_int->next);
}