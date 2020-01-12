#include "inputHandler.hpp"
#include  <iostream>
#include "moveCommand.hpp"

command* inputHandler::handleInput(std::shared_ptr<gameObject> objectForInput){

    for( auto i : moveKeys){
        if(sf::Keyboard::isKeyPressed(i)){
            command* newMoveCommand = new moveCommand( objectForInput, i );
            return newMoveCommand;
        }
    }


    return NULL;
}



