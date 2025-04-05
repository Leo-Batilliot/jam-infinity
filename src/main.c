/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** main.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "project.h"
#include "linked_list.h"

int main(void)
{
    infinity_t *main_struct = malloc(sizeof(infinity_t));

    if (!main_struct)
        return 84;
    main_struct->head = linked_list_create();
    if (!main_struct->head)
        return 84;
    algo(main_struct);
    linked_list_destroy(main_struct->head);
    free(main_struct);
    return 84;
}
