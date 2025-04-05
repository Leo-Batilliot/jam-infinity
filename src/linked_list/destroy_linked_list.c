/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** destroy_linked_list.c
*/

#include <stdlib.h>
#include "linked_list.h"

void linked_list_destroy(linked_list_t *linked_list)
{
    Linked_list_node_t *tmp = linked_list->start;
    Linked_list_node_t *to_destroy;

    while (tmp) {
        to_destroy = tmp;
        tmp = tmp->next;
        if (to_destroy->data_destroy_function && to_destroy->data)
            to_destroy->data_destroy_function(to_destroy->data);
        to_destroy->data = NULL;
        free(to_destroy);
    }
    free(linked_list);
}
