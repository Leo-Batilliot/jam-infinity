/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.cpp
*/

#include "project.h"
#include "Display.hpp"

Display::Display()
    :_window(nullptr)
{
    this->_window = std::make_unique<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Display", sf::Style::Default);
    this->_window->setFramerateLimit(60);
}

Display::~Display()
{
    this->_window->close();
}

std::vector<std::shared_ptr<sf::Texture>> initTexture()
{
    std::vector<std::shared_ptr<sf::Texture>> textures(8);
    for (auto& tex : textures)
        tex = std::make_shared<sf::Texture>();

    textures[0]->loadFromFile("assets/Katatsumuri.png");
    textures[1]->loadFromFile("assets/Hito.png");
    textures[2]->loadFromFile("assets/Inu.png");
    textures[3]->loadFromFile("assets/Jitensha_ni_notta_otoko.png");
    textures[4]->loadFromFile("assets/Kuruma.png");
    textures[5]->loadFromFile("assets/Densha.png");
    textures[6]->loadFromFile("assets/Hikoki.png");
    textures[7]->loadFromFile("assets/Fenikkusu.png");
    return textures;
}

std::vector<sf::Sprite> initSprite(std::shared_ptr<sf::Texture> texture)
{
    std::vector<sf::Sprite> sprites(9);

    sprites[0].setTexture(texture.get()[0]);
    sprites[0].setPosition({170, 910});
    sprites[0].scale({0.09, 0.09});

    for (int i = 1; i < 9; i++) {
        sprites[i].setTexture(texture.get()[0]);
        sprites[i].scale({0.09, 0.09});
        sprites[i].setPosition({170, sprites[i - 1].getPosition().y - 85});
    }
    return sprites;
}

void Display::Run(infinity_t *main_struct)
{
    std::vector<std::shared_ptr<sf::Texture>>  textures = initTexture();
    std::vector<sf::Sprite> sprite = initSprite(textures[7]);

    while (true) {
        algo(main_struct);
        this->_window->clear();
        while (this->_window->pollEvent(this->_event))
            if (this->_event.type == sf::Event::Closed)
                return;
        for (int i = 0; i < 9; i++)
            this->_window->draw(sprite[i]);
        this->_window->display();
    }
}
