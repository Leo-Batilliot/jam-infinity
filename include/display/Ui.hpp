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
        sf::VertexArray getTopBackground() const;
        sf::VertexArray getBackground() const;
        sf::VertexArray createRoundedRectangle(sf::Vector2f pos, sf::Vector2f size, float radius, const sf::Color& color, unsigned int cornerPoints = 8);
        void changeColor(sf::VertexArray &button, const sf::Color& color);
    
    private:
        sf::VertexArray _topBackground;
        sf::VertexArray _background;
};
