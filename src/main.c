/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "linked_list.h"

typedef struct truc_s {
    int caca;
} truc_t;

int main(void)
{
    linked_list_t *list = linked_list_create();
    truc_t *a = malloc(sizeof(truc_t));
    truc_t *b = malloc(sizeof(truc_t));
    truc_t *c = malloc(sizeof(truc_t));
    truc_t *d = malloc(sizeof(truc_t));

    a->caca = 10;
    b->caca = 69;
    c->caca = 1000;
    d->caca = 789465;
    linked_list_add(list, a, free);
    linked_list_add(list, b, free);
    linked_list_add(list, c, free);
    linked_list_add(list, d, free);

    do {
        printf("%i\n", ((truc_t *)linked_list_get_data(list))->caca);
    } while (linked_list_next(list));
    linked_list_destroy(list);
    return 84;
}
