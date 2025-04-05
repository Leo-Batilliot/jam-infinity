/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.hpp
*/

#pragma once

#include <memory>
#include "project.h"
#include "Ui.hpp"
#include <SFML/Graphics.hpp>

class Display
{
    public:
        Display();
        ~Display();

        void Run(infinity_t *main_struct);
    private:
        Ui _ui;
        std::shared_ptr<sf::RenderWindow> _window;
        sf::Event _event;
};
