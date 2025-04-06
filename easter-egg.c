/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** easter-egg.c
*/

#include "ncurses.h"
#include <string.h>
int easter_egg(void)
{
    WINDOW *fenster;
    int hoehe = 10;
    int breite = 40;
    char *nachricht1 = "TOLL! DU HAST DAS EASTER EGG GEFUNDEN!";
    char *nachricht2 = "Drücke eine Taste zum Beenden    ";

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    fenster = newwin(hoehe, breite, (LINES - hoehe) / 2, (COLS - breite) / 2);
    box(fenster, 0, 0);
    mvwprintw(fenster, 2, (breite - strlen(nachricht1)) / 2, "%s", nachricht1);
    mvwprintw(fenster, 4, (breite - strlen(nachricht2)) / 2, "%s", nachricht2);
    wrefresh(fenster);
    wgetch(fenster);
    delwin(fenster);
    endwin();
    return 0;
}