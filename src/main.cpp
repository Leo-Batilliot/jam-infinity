/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** main.cpp
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "project.h"
#include "linked_list.h"

#include "Display.hpp"

int main(void)
{
    infinity_t *main_struct = (infinity_t *)malloc(sizeof(infinity_t));

    if (!main_struct)
        return 84;
    main_struct->head = linked_list_create();
    main_struct->is_buy = 0;
    if (!main_struct->head)
        return 84;
    main_struct->money_tot = 0;
    for (int i = 0; i < NB_OBJ; i++) {
        truc_t *node = (truc_t *)malloc(sizeof(truc_t));
        if (!node)
            return 84;
        node->coeff = 1;
        node->index = i + 1;
        node->start = 10 * node->index;
        gettimeofday(&node->timer, NULL);
        node->pos = 1;
        linked_list_add(main_struct->head, node, free);
    }
    Display display;
    display.Run(main_struct);
    algo(main_struct);
    linked_list_destroy(main_struct->head);
    free(main_struct);
    return 84;
}
