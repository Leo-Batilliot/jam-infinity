/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** create_linked_list.c
*/

#include <stdlib.h>
#include "linked_list.h"

linked_list_t *linked_list_create(void)
{
    linked_list_t *linked_list = (linked_list_t *)malloc(sizeof(linked_list_t));

    if (!linked_list)
        return NULL;
    linked_list->size = 0;
    linked_list->current = NULL;
    linked_list->current_index = 0;
    linked_list->start = NULL;
    linked_list->end = NULL;
    return linked_list;
}
