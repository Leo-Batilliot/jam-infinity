/*
** EPITECH PROJECT, 2025
** JAM-Infinity
** File description:
** Object
*/

#pragma once

#include <memory>
#include "project.h"
#include "Ui.hpp"
#include <SFML/Graphics.hpp>

class Object {
    public:
        Object(Ui &ui, sf::Font &font, int i);
        ~Object();

        void setTextLevel(const std::string &str);
        void setTextMult(const std::string &str);
        void setObject(truc_t *object);

        sf::Text getMult();
        sf::Text getLevel();
        sf::VertexArray getButton();
        truc_t *getObject();
    private:
        sf::VertexArray _button;
        sf::Text _mult;
        sf::Text _level;
        truc_t *_object;
};
