/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** Ui
*/

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ui {
    public:
        Ui();
        ~Ui();

        void display(sf::RenderWindow *window);
        sf::RectangleShape initSquare(sf::Vector2f pos, sf::Color color, sf::Vector2f size);
        sf::RectangleShape getBackground() const;
    
    private:
        sf::RectangleShape _topBackground;;
};
