/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** easter-egg.c
*/

#include "ncurses.h"
#include <string.h>
#include <string>

int easter_egg(void)
{
    WINDOW *fenster;
    int hoehe = 10;
    int breite = 40;
    std::string easter_egg = "TOLL! DU HAST DAS EASTER EGG GEFUNDEN!";
    std::string easter_egg2 = "Drücke eine Taste zum Beenden    ";
    auto nachricht1 = easter_egg.c_str();
    auto nachricht2 = easter_egg2.c_str();

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    fenster = newwin(hoehe, breite, (LINES - hoehe) / 2, (COLS - breite) / 2);
    box(fenster, 0, 0);
    mvwprintw(fenster, 2, (breite - strlen(nachricht1)) / 2, "%s", nachricht1);
    mvwprintw(fenster, 4, (breite - strlen(nachricht2)) / 2, "%s", nachricht2);
    wrefresh(fenster);

    nodelay(fenster, TRUE);
    for (int i = 0; i < 30; i++) {
        napms(100);
        if (wgetch(fenster) != ERR) {
            break;
        }
    }
    delwin(fenster);
    endwin();
    return 0;
}