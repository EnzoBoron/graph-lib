#include "tree.h"

void erreur_malloc(const char *message, int exit_code)
{
    write(2, message, strlen(message));
    exit(exit_code);
}