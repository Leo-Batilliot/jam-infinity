/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** linked_list_node_create.c
*/

#include <stdlib.h>
#include "linked_list.h"

Linked_list_node_t *linked_list_node_create(void *data, void (*data_destroy_function)(void *))
{
    Linked_list_node_t *new_node = (Linked_list_node_t *)malloc(sizeof(Linked_list_node_t));

    if (!new_node)
        return NULL;
    new_node->data = data;
    new_node->data_destroy_function = data_destroy_function;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
