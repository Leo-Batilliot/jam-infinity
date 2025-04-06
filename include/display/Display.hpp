/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.hpp
*/

#pragma once

#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

#include "Ui.hpp"
#include "project.h"

class Display
{
    public:
        Display();
        ~Display();

        void Run(infinity_t *main_struct);

        std::vector<std::shared_ptr<sf::Texture>> initTextureObject();
        std::vector<std::shared_ptr<sf::Texture>> initTexturePortaux();
        std::vector<std::shared_ptr<sf::SoundBuffer>> initSoundBuffer();
        std::vector<sf::Sprite> initSprite(std::shared_ptr<sf::Texture> texture);
        std::vector<std::pair<sf::Sprite, sf::Sprite>> initSpritePortaux(std::vector<std::shared_ptr<sf::Texture>> texture_portaux);

        void drawObject(infinity_t *main_struct);
        bool checkEvent(infinity_t *main_struct);
        void checkButton(infinity_t *main_struct);
    
    private:
        Ui _ui;

        sf::Font _font;
        sf::Event _event;
        sf::RectangleShape _hiddenButton;
        std::shared_ptr<sf::RenderWindow> _window;
        std::vector<sf::Text> _x;

        std::vector<Object> _object;

        std::vector<sf::Sprite> _sprites;
        std::vector<std::shared_ptr<sf::Texture>> _textures;
        std::vector<std::shared_ptr<sf::SoundBuffer>> _soundBuffers;
        std::vector<std::pair<sf::Sprite, sf::Sprite>> _portails;
        std::vector<std::shared_ptr<sf::Texture>> _textures_portaux;
};
