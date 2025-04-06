/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.cpp
*/

#include <thread>
#include <chrono>

#include "Ui.hpp"
#include "project.h"
#include "Display.hpp"
#include <cmath>

Display::Display()
    :_window(nullptr)
{
    this->_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Infinity", sf::Style::Default);
    this->_window->setFramerateLimit(60);
    this->_ui = Ui();
    this->_font.loadFromFile("assets/Monocraft.ttf");
    this->_textures = initTextureObject();
    this->_soundBuffers = initSoundBuffer();
    this->_textures_portaux = initTexturePortaux();
    this->_sprites = initSprite(this->_textures[0]);
    this->_portails = initSpritePortaux(this->_textures_portaux);

    for (int i = 0; i < 9; i++) {
        Object obj(this->_ui, this->_font, i);
        this->_object.push_back(obj);
    }
    this->_x = std::vector<sf::Text>(8);
    for (int i = 0; i <= 7; i++) {
        this->_x[i].setFont(this->_font);
        this->_x[i].setCharacterSize(30);
        this->_x[i].setFillColor(sf::Color(255, 255, 255, 255));
        this->_x[i].setPosition(250 + i * 200, 50);
        this->_x[i].setString("x");
    }
    _hiddenButton = sf::RectangleShape();
    _hiddenButton.setSize(sf::Vector2f(100, 100));
    _hiddenButton.setPosition(800, 980);
}

Display::~Display()
{
    this->_window->close();
}

std::vector<std::shared_ptr<sf::Texture>> Display::initTextureObject()
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

std::vector<std::shared_ptr<sf::Texture>> Display::initTexturePortaux()
{
    std::vector<std::shared_ptr<sf::Texture>> textures(2);

    textures[0] = std::make_shared<sf::Texture>();
    textures[1] = std::make_shared<sf::Texture>();
    textures[0]->loadFromFile("assets/Hidari_no_potaru.png");
    textures[1]->loadFromFile("assets/Migi_no_potaru.png");
    return textures;
}

std::vector<sf::Sprite> Display::initSprite(std::shared_ptr<sf::Texture> texture)
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
        sf::Color(233, 31, 220),
        sf::Color(255, 255, 255)
    };
    sprites[0].setTexture(texture.get()[0]);
    sprites[0].setPosition({170, 910});
    sprites[0].scale({0.09, 0.09});
    sprites[0].setColor(colors[0]);
    for (int i = 1; i < 9; i++) {
        sprites[i].setTexture(texture.get()[0]);
        sprites[i].scale({0.09, 0.09});
        sprites[i].setPosition({170, sprites[i - 1].getPosition().y - 85});
        sprites[i].setColor(colors[i]);
    }
    return sprites;
}

std::vector<std::shared_ptr<sf::SoundBuffer>> Display::initSoundBuffer()
{
    std::vector<std::shared_ptr<sf::SoundBuffer>> soundBuffers(8);
    for (auto& tex : soundBuffers)
        tex = std::make_shared<sf::SoundBuffer>();

    soundBuffers[0]->loadFromFile("assets/audio/Schnecke.wav");
    soundBuffers[1]->loadFromFile("assets/audio/Schrittgeräusch.wav");
    soundBuffers[2]->loadFromFile("assets/audio/Hund.wav");
    soundBuffers[3]->loadFromFile("assets/audio/Radfahrer.wav");
    soundBuffers[4]->loadFromFile("assets/audio/Auto.wav");
    soundBuffers[5]->loadFromFile("assets/audio/Zug.wav");
    soundBuffers[6]->loadFromFile("assets/audio/Flugzeug.wav");
    soundBuffers[7]->loadFromFile("assets/audio/Phönix.wav");
    return soundBuffers;
}

std::vector<std::pair<sf::Sprite, sf::Sprite>> Display::initSpritePortaux(std::vector<std::shared_ptr<sf::Texture>> texture_portaux)
{
    std::vector<sf::Sprite> portails_left(9);
    std::vector<sf::Sprite> portails_right(9);
    std::vector<std::pair<sf::Sprite, sf::Sprite>> portails(9);

    for (int i = 0; i < 9; i++) {
        portails_left[i].setTexture(texture_portaux[0].get()[0]);
        portails_left[i].scale({0.09, 0.09});
        portails_left[i].setPosition(130, static_cast<float>(910 - (i * 85)));
        portails_right[i].setTexture(texture_portaux[1].get()[0]);
        portails_right[i].scale({0.09, 0.09});
        portails_right[i].setPosition(1600.0, static_cast<float>(910 - (i * 85)));
    }
    for (int i = 0; i < 9; i++) {
        portails[i].first = portails_left[i];
        portails[i].second = portails_right[i];
    }
    return portails;
}

void Display::drawObject(infinity_t *main_struct)
{
    int index = 0;

    this->_window->clear();
    do {
        truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);
        _sprites[index].setPosition({170 + node->pos * 14, _sprites[index].getPosition().y});
        _object[index].setTextLevel(std::to_string(node->level));
        _object[index].setTextMult(std::to_string(node->coeff));
        index++;
        if (node->pos == 0) {
            std::thread([](std::shared_ptr<sf::SoundBuffer> buffer) {
                sf::Sound sound;
                sound.setBuffer(*buffer);
                sound.play();
                while (sound.getStatus() == sf::Sound::Playing)
                    sf::sleep(sf::milliseconds(200));
            }, this->_soundBuffers[4]).detach();
        }
    } while (linked_list_next(main_struct->head));

    this->_window->draw(this->_ui.getBackground());
    this->_window->draw(this->_ui.getTopBackground());
    for (int i = 0; i < 9; i++) {
        if (i <= 8 && i > 0) {
            this->_window->draw(_x[i - 1]);
        }
        this->_window->draw(_object[i].getMult());
        if (main_struct->is_buy >= i) {
            this->_window->draw(_sprites[i]);
            this->_window->draw(_portails[i].first);
            this->_window->draw(_portails[i].second);
            this->_window->draw(_object[i].getButton());
            this->_window->draw(_object[i].getLevel());
        }
        else if (main_struct->is_buy + 1 >= i) {
            this->_window->draw(_object[i].getButton());
            this->_window->draw(_object[i].getLevel());
        }
    }
    this->_window->display();
    for (int i = 0; i < 9; i++) {
        auto button = _object[i].getButton();
        _ui.changeColor(button, sf::Color(128, 163, 163, 255));
    }
}

int get_price(int index, int level, int prestige)
{
    return pow(5, index + 1) * pow(1.05, level) * pow(2, prestige);
}

float get_speed(int index, int level)
{
    float limit[] = {70.0, 50.0, 40.0, 30.0, 25.0, 20.0, 15.0, 10.0, 5.0};
    float a = 0.2f;
    float growth = 1.0f - 1.0f / pow(level + 1.0f, a);
    return (1.0f / (index + 1) + (limit[index] / 10.0f) * growth);
}

void Display::checkButton(infinity_t *main_struct)
{
    for (int i = 0; i < 9; i++) {
        auto button = _object[i].getButton();
        if (button.getBounds().contains(this->_event.mouseButton.x, this->_event.mouseButton.y)) {
            if (i <= main_struct->is_buy) {
                _ui.changeColor(button, sf::Color(0, 255, 0, 255));
                _object[i].getObject()->level++;
            }
            else if (i == main_struct->is_buy + 1) {
                main_struct->is_buy++;
                _object[i].getObject()->level++;
                _ui.changeColor(button, sf::Color(0, 255, 0, 255));
                _object[i].getObject()->speed = get_speed(_object[i].getObject()->index, _object[i].getObject()->level);
            }
        }
        linked_list_next(main_struct->head);
    }
    int result = 0;
    for (int i = 0; i < 9; i++) {
        auto object = _object[i].getObject();
        result += object->coeff;
    }
    if (this->_hiddenButton.getGlobalBounds().contains(this->_event.mouseButton.x, this->_event.mouseButton.y) && result >= 15)
        easter_egg();
}

bool Display::checkEvent(infinity_t *main_struct)
{
    if (this->_event.type == sf::Event::Closed)
        return false;
    if (this->_event.type == sf::Event::MouseButtonPressed) {
        if (this->_event.mouseButton.button == sf::Mouse::Left) {
            checkButton(main_struct);
        }
    }
    return true;
}

void Display::Run(infinity_t *main_struct)
{
    sf::Clock clock;

    do {
        truc_t *node = (truc_t *)linked_list_get_data(main_struct->head);
        _object[node->index - 1].setObject(node);
    } while (linked_list_next(main_struct->head));

    while (_window->isOpen()) {
        if (clock.getElapsedTime().asSeconds() < 1.0 / 60.0)
            continue;
        clock.restart();
        algo(main_struct);
        while (this->_window->pollEvent(this->_event))
            if (!this->checkEvent(main_struct))
                return;
        this->drawObject(main_struct);
    }
}
