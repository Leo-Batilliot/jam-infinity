/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** Object
*/

#include "Object.hpp"

Object::Object(Ui &ui, sf::Font &font, int i)
{
    std::vector<sf::Color> colors = {
        sf::Color(175, 0, 0),
        sf::Color(255, 165, 0),
        sf::Color(255, 255, 0),
        sf::Color(57, 255, 57),
        sf::Color(57, 255, 255),
        sf::Color(27, 30, 219),
        sf::Color(150, 31, 122),
        sf::Color(233, 31, 220)
    };
    _button = ui.createRoundedRectangle(sf::Vector2f(10, 910 - (i * 85)),
        sf::Vector2f(130, 80), 20, colors[i], 8);

    _object = nullptr;
    _level = sf::Text();
    _level.setFont(font);
    _level.setCharacterSize(30);
    _level.setFillColor(sf::Color(0, 0, 0, 255));
    _level.setPosition(30, 910 - (i * 85));
    _mult = sf::Text();
    _mult.setFont(font);
    _mult.setCharacterSize(30);
    _mult.setFillColor(colors[i]);
    _mult.setPosition(80 + i * 200, 50);
}

Object::~Object()
{
}

void Object::setTextLevel(const std::string &str)
{
    _level.setString(str);
}

void Object::setTextMult(const std::string &str)
{
    _mult.setString(str);
}

sf::Text Object::getMult()
{
    return _mult;
}

sf::Text Object::getLevel()
{
    return _level;
}

sf::VertexArray Object::getButton()
{
    return _button;
}

truc_t *Object::getObject()
{
    return _object;
}

void Object::setObject(truc_t *object)
{
    _object = object;
}