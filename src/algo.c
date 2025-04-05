/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** algo
*/

#include "linked_list.h"
#include "project.h"

long get_time_in_ms(struct timeval *start_time) 
{
    struct timeval current_time;

    gettimeofday(&current_time, NULL);
    return (current_time.tv_sec - start_time->tv_sec) * 1000 + (current_time.tv_usec - start_time->tv_usec) / 1000;
}

int algo(infinity_t *main_struct)
{
    main_struct->money_tot = 0;

    for (int i = 0; i < NB_OBJ; i++) {
        truc_t *node = malloc(sizeof(truc_t));
        if (!node)
            return 84;
        node->coeff = 1;
        node->index = i + 1;
        node->start = 10 * node->index;
        gettimeofday(&node->timer, NULL);
        node->pos = 1;
        linked_list_add(main_struct->head, node, free);
    }
    while (1) {
        do {
            truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);
            long elapsed = get_time_in_ms(&node->timer);
            float elapsed_seconds = (float)elapsed / 1000.0;
            node->pos = ((float)elapsed / (float)(node->start * 1000)) * 100;

            if (elapsed_seconds >= node->start) {
                main_struct->money_tot = 1;
                // récupérer value des coeffs coté front
                gettimeofday(&node->timer, NULL);
                do {
                    truc_t *tmp = (truc_t *)linked_list_get_data(main_struct->head);
                    main_struct->money_tot *= tmp->coeff;
                } while (linked_list_next(main_struct->head));
            }
        } while (linked_list_next(main_struct->head));
    }
    return 84;
}