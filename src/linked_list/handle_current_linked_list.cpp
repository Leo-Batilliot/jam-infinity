/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** handle_current_linked_list.c
*/

#include <stddef.h>
#include "linked_list.h"

void linked_list_set_to_start(linked_list_t *linked_list)
{
    if (linked_list->current)
        linked_list->start = linked_list->current;
    linked_list->current_index = 0;
}

void *linked_list_get_data(linked_list_t *linked_list)
{
    if (linked_list->current)
        return linked_list->current->data;
    return NULL;
}

Linked_list_node_t *linked_list_get_current(linked_list_t *linked_list)
{
    return linked_list->current;
} 

void linked_list_set_current(linked_list_t *linked_list, Linked_list_node_t *node)
{
    linked_list->current = node;
}

unsigned int linked_list_get_size(linked_list_t *linked_list)
{
    return linked_list->size;
}

bool linked_list_next(linked_list_t *linked_list)
{
    if (!linked_list->current)
        return false;
    if (!linked_list->current->next) {
        linked_list->current = linked_list->start;
        linked_list->current_index = 0;
        return false;
    }
    linked_list->current = linked_list->current->next;
    linked_list->current_index++;
    return true;
}

bool linked_list_prev(linked_list_t *linked_list)
{
    if (!linked_list->current->prev)
        return false;
    linked_list->current = linked_list->current->prev;
    linked_list->current_index--;
    return true;
}
