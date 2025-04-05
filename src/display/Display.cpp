/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.cpp
*/

#include "project.h"
#include "Display.hpp"
#include "Ui.hpp"

Display::Display()
    :_window(nullptr)
{
    this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Display", sf::Style::Default);
    this->_window->setFramerateLimit(60);
    this->_ui = Ui();
}

Display::~Display()
{
    this->_window->close();
}

std::vector<std::shared_ptr<sf::Texture>> initTextureObject()
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

std::vector<std::shared_ptr<sf::Texture>> initTexturePortaux()
{
    std::vector<std::shared_ptr<sf::Texture>> textures(2);

    textures[0] = std::make_shared<sf::Texture>();
    textures[1] = std::make_shared<sf::Texture>();
    textures[0]->loadFromFile("assets/Hidari_no_potaru.png");
    textures[1]->loadFromFile("assets/Migi_no_potaru.png");
    return textures;
}

std::vector<sf::Sprite> initSprite(std::shared_ptr<sf::Texture> texture)
{
    std::vector<sf::Sprite> sprites(9);
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
    sprites[0].setTexture(texture.get()[0]);
    sprites[0].setPosition({170, 910});
    sprites[0].scale({0.09, 0.09});
    for (int i = 1; i < 9; i++) {
        sprites[i].setTexture(texture.get()[0]);
        sprites[i].scale({0.09, 0.09});
        sprites[i].setPosition({170, sprites[i - 1].getPosition().y - 85});
        sprites[i].setColor(colors[i - 1]);
    }
    return sprites;
}

std::pair<std::vector<sf::Sprite>, std::vector<sf::Sprite>> initSpritePortaux(std::vector<std::shared_ptr<sf::Texture>> texture_portaux)
{
    std::vector<sf::Sprite> portails_left(9);
    std::vector<sf::Sprite> portails_right(9);
    for (int i = 0; i < 9; i++) {
        portails_left[i].setTexture(texture_portaux[0].get()[0]);
        portails_left[i].scale({0.09, 0.09});
        portails_left[i].setPosition(130, static_cast<float>(910 - (i * 85)));
        portails_right[i].setTexture(texture_portaux[1].get()[0]);
        portails_right[i].scale({0.09, 0.09});
        portails_right[i].setPosition(1600.0, static_cast<float>(910 - (i * 85)));
    }
    return {portails_left, portails_right};
}

void Display::Run(infinity_t *main_struct)
{
    sf::Clock clock;
    std::vector<std::shared_ptr<sf::Texture>>  textures = initTextureObject();
    std::vector<std::shared_ptr<sf::Texture>> textures_portaux = initTexturePortaux();
    std::vector<sf::Sprite> sprites = initSprite(textures[0]);
    std::pair<std::vector<sf::Sprite>, std::vector<sf::Sprite>> portails = initSpritePortaux(textures_portaux);

    while (true) {
        if (clock.getElapsedTime().asSeconds() < 1.0 / 60.0)
            continue;
        clock.restart();
        algo(main_struct);
        this->_window->clear();
        while (this->_window->pollEvent(this->_event))
            if (this->_event.type == sf::Event::Closed)
                return;
        int index = 0;
        do {
            truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);
            sprites[index].setPosition({170 + node->pos * 14, sprites[index].getPosition().y});
            index++;
        } while (linked_list_next(main_struct->head));
        this->_window->draw(this->_ui.getBackground());
        this->_window->draw(this->_ui.getTopBackground());
        for (int i = 0; i < 9; i++) {
            this->_window->draw(portails.first[i]);
            this->_window->draw(sprites[i]);
            this->_window->draw(portails.second[i]);
        }
        this->_window->display();
    }
}
