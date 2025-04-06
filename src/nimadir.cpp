/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** algo
*/

// langue : Ouzbek

#include "linked_list.h"
#include "project.h"

float pulni_kur(infinity_t *asosiy_strukt)
{
    int j = 0;
    float joriy = 1;
    linked_list_t *vaqtinchalik = asosiy_strukt->head;
    linked_list_set_to_start(vaqtinchalik);

    do {
        truc_t *vaqtinchalik_tugun = (truc_t *)linked_list_get_data(vaqtinchalik);
        joriy *= vaqtinchalik_tugun->coeff;
        j++;
    } while (linked_list_next(vaqtinchalik) && j <= asosiy_strukt->is_buy);
    linked_list_set_to_start(vaqtinchalik);
    return joriy;
}

void nimadir(infinity_t *asosiy_strukt)
{
    int i = 0;
    int oxirgi_holat = 0;

    do {
        truc_t *tugun = (truc_t *)linked_list_get_data(asosiy_strukt->head);

        tugun->pos += tugun->speed;
        if (tugun->pos >= 100 && tugun->level <= 100) {
            tugun->pos = 0;
            tugun->coeff += 0.01 * (tugun->legacy * 2) - 0.01;
            asosiy_strukt->money_tot += pulni_kur(asosiy_strukt);
            oxirgi_holat = tugun->state;
            tugun->state = tugun->level / 10;
            tugun->state = tugun->state > 7 ? 7 : tugun->state;
            if (oxirgi_holat != tugun->state)
                tugun->state_change = true;
        }
        i++;
    } while (linked_list_next(asosiy_strukt->head) && i <= asosiy_strukt->is_buy);
    linked_list_set_to_start(asosiy_strukt->head);
}