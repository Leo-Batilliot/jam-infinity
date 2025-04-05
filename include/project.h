/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define NB_OBJ 9

    #include "linked_list.h"
    #include <stdio.h>
    #include <time.h>
    #include <sys/time.h>
    #include <stdlib.h>
    #include <stddef.h>

typedef struct truc_s {
    float pos;
    float start;
    float coeff;
    int index;
    struct timeval timer;
} truc_t;

typedef struct infinity_s {
    float money_tot;
    int is_buy;
    linked_list_t *head;
} infinity_t;

void algo(infinity_t *main_struct);

#endif /* !MY_H_ */
