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

void algo(infinity_t *main_struct)
{
    int i = 0;

    do {
        truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);
        long elapsed = get_time_in_ms(&node->timer);
        float elapsed_seconds = (float)elapsed / 1000.0;

        node->pos = ((float)elapsed / (float)(node->start * 1000)) * 100 * node->speed;
        if (elapsed_seconds >= node->start) {
            // exemple pour tester
            node->level += 2;
            node->speed = 1.0f + (node->level - 1) * 0.5f;
            node->coeff += 0.01;
            main_struct->money_tot = 1;
            gettimeofday(&node->timer, NULL);
            int j = 0;
            do {
                truc_t *tmp_node = (truc_t *)linked_list_get_data(main_struct->head);
                main_struct->money_tot *= tmp_node->coeff;
                j++;
            } while (linked_list_next(main_struct->head) && j < main_struct->is_buy);
        }
        i++;
    } while (linked_list_next(main_struct->head) && i < main_struct->is_buy);
    linked_list_set_to_start(main_struct->head);
}