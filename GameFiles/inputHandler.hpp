#ifndef _INPUTHANDLER_HPP
#define _INPUTHANDLER_HPP

#include "command.hpp"
#include <SFML/Graphics.hpp>
#include <array>


class inputHandler{
private:
    std::array<sf::Keyboard::Key, 4>  moveKeys = {
        sf::Keyboard::Up, sf::Keyboard::Down,
        sf::Keyboard::Left, sf::Keyboard::Right};
public:

    inputHandler(){}

    command* handleInput(std::shared_ptr<gameObject> objectForInput);
};

#endif