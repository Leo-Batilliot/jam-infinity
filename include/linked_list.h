/*
** EPITECH PROJECT, 2024
** Kage-No-Jidai
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H
    #define LINKED_LIST_H

    #include <stdbool.h>

typedef struct linked_list_node_s {
    void *data;
    void (*data_destroy_function)(void *);
    struct linked_list_node_s *next;
    struct linked_list_node_s *prev;
} Linked_list_node_t;

typedef struct linked_list_s {
    unsigned int size;
    Linked_list_node_t *start;
    Linked_list_node_t *end;
    Linked_list_node_t *current;
    unsigned int current_index;
} linked_list_t;

void linked_list_destroy(linked_list_t *);
void linked_list_set_to_start(linked_list_t *linked_list);
void linked_list_set_current(linked_list_t *linked_list, Linked_list_node_t *node);

void *linked_list_get_data(linked_list_t *linked_list);
void *linked_list_pop(linked_list_t *linked_list, unsigned int index);

int linked_list_add(linked_list_t *linked_list, void *data, void (*data_destroy_function)(void *));

unsigned int linked_list_get_size(linked_list_t *linked_list);

bool linked_list_next(linked_list_t *linked_list);
bool linked_list_prev(linked_list_t *linked_list);

linked_list_t *linked_list_create(void);

Linked_list_node_t *linked_list_get_current(linked_list_t *linked_list);
Linked_list_node_t *linked_list_node_create(void *data, void (*data_destroy_function)(void *));

#endif
