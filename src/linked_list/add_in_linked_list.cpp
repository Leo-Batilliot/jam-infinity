/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** add_in_linked_list.c
*/

#include "linked_list.h"

int linked_list_add(linked_list_t *linked_list, void *data, void (*data_destroy_function)(void *))
{
    Linked_list_node_t *new_node = linked_list_node_create(data, data_destroy_function);

    if (!new_node)
        return 84;
    if (linked_list->size == 0) {
        linked_list->start = new_node;
        linked_list->end = new_node;
        linked_list->current = new_node;
    } else {
        new_node->prev = linked_list->end;
        linked_list->end->next = new_node;
        linked_list->end = new_node;
    }
    linked_list->size++;
    return 0;
}
