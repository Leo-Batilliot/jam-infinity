/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** Ui
*/

#include "Ui.hpp"
#include <math.h>

Ui::Ui()
{
    _topBackground = initSquare(sf::Vector2f(0, 0), sf::Color(37, 37, 60, 255), sf::Vector2f(1920, 200));
}

Ui::~Ui()
{
}

sf::RectangleShape Ui::initSquare(sf::Vector2f pos, sf::Color color, sf::Vector2f size)
{
    sf::RectangleShape square(size);
    square.setPosition(pos);
    square.setFillColor(color);
    return square;
}


void Ui::display(sf::RenderWindow *window)
{
    window->draw(_topBackground);
}

sf::RectangleShape Ui::getBackground() const
{
    return _topBackground;
}