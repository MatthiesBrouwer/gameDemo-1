#ifndef _MOVECOMMAND_HPP
#define _MOVECOMMAND_HPP

#include "command.hpp"
#include <iostream>
#include <map>
#include "memory"

std::map<sf::Keyboard::Key, sf::Vector2f> directionMap{ 
    {sf::Keyboard::Left, sf::Vector2f(-1.0, 0.0)},
    {sf::Keyboard::Right, sf::Vector2f(1.0, 0.0)},
    {sf::Keyboard::Up, sf::Vector2f(0.0, -1.0)},
    {sf::Keyboard::Down, sf::Vector2f(0.0, 1.0)}
  };

class moveCommand : public command{
private:
    std::shared_ptr<gameObject> objectToMove;
    sf::Keyboard::Key directionKey;
public:
    moveCommand(std::shared_ptr<gameObject> objectToMove, sf::Keyboard::Key directionKey):
    objectToMove(objectToMove),
    directionKey(directionKey)
    {}

    virtual void execute(){
        objectToMove->move(directionMap[directionKey]);
    }

    virtual void undo(){}
};
#endif