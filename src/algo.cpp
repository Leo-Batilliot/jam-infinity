/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** algo
*/

#include "linked_list.h"
#include "project.h"

float get_cur_money(infinity_t *main_struct)
{
    int j = 0;
    float cur = 1;

    do {
        truc_t *tmp_node = (truc_t *)linked_list_get_data(main_struct->head);
        cur *= tmp_node->coeff;
        j++;
    } while (linked_list_next(main_struct->head) && j < main_struct->is_buy);
    linked_list_set_to_start(main_struct->head);
    return cur;
}

void algo(infinity_t *main_struct)
{
    int i = 0;

    do {
        truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);

        node->pos += node->speed;
        if (node->pos >= 100 && node->level <= 100) {
            node->pos = 0;
            node->coeff += 0.01;
            main_struct->money_tot += get_cur_money(main_struct);
        }
        i++;
    } while (linked_list_next(main_struct->head) && i <= main_struct->is_buy);
    linked_list_set_to_start(main_struct->head);
}