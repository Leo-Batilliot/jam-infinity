/*
** EPITECH PROJECT, 2024
** JAM-Infinity
** File description:
** Display.hpp
*/

#include <memory>
#include <SFML/Graphics.hpp>

class Display
{
    public:
        Display();
        ~Display();

        void Run(infinity_t *main_struct);
    private:
        std::unique_ptr<sf::RenderWindow> _window;
        sf::Event _event;
};
