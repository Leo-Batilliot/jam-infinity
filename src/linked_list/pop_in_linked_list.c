/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** pop_in_linked_list.c
*/

#include <stdlib.h>
#include "linked_list.h"

static Linked_list_node_t *get_node_forward(Linked_list_node_t *node, int index)
{
    Linked_list_node_t *tmp = node;

    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp;
}

static Linked_list_node_t *get_node_backward(Linked_list_node_t *node, int index, int size)
{
    Linked_list_node_t *tmp = node;

    for (int i = size - 1; i > index; i--)
        tmp = tmp->prev;
    return tmp;
}

static Linked_list_node_t *get_node(linked_list_t *linked_list, unsigned int index)
{
    unsigned int end_distance = linked_list->size - index - 1;
    unsigned int current_distance = abs((int)(linked_list->current_index - index));

    if (index < end_distance && index <= current_distance)
        return get_node_forward(linked_list->start, index);
    else if (end_distance < index && end_distance <= current_distance)
        return get_node_backward(linked_list->end, index, linked_list->size);
    else if (index > linked_list->current_index)
        return get_node_forward(linked_list->current, index);
    else
        return get_node_backward(linked_list->current, index, linked_list->size);
}

static void set_new_start_end_and_current(linked_list_t *linked_list, unsigned int index)
{
    if (index == 0)
        linked_list->start = linked_list->start->next;
    else if (index == linked_list->size - 1)
        linked_list->end = linked_list->end->prev;
    if (index == linked_list->current_index) {
        if (linked_list->current->next) {
            linked_list->current = linked_list->current->next;
            linked_list->current_index++;
        } else {
            linked_list->current = linked_list->start;
            linked_list->current_index = 0;
        }
    }
}

static void remove_node(Linked_list_node_t *node)
{
    if (node->prev)
        node->prev->next = node->next;
    if (node->next)
        node->next->prev = node->prev;
    free(node);
}

void *linked_list_pop(linked_list_t *linked_list, unsigned int index)
{
    void *data;
    Linked_list_node_t *node;

    if (index >= linked_list->size || linked_list->size == 0)
        return NULL;
    node = get_node(linked_list, index);
    data = node->data;
    set_new_start_end_and_current(linked_list, index);
    remove_node(node);
    linked_list->size--;
    return data;
}
