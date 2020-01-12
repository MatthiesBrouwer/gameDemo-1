#ifndef _GAMECONTROL_HPP
#define _GAMECONTROL_HPP
#include <SFML/Graphics.hpp>
#include <ctime>
#include "command.hpp"
#include "inputHandler.hpp"
#include "renderer.hpp"
class gameControl{
private:
    sf::RenderWindow& window;
    inputHandler gameInputHandler;
    renderer objectRenderer;
    time_t timerPrevious;
    time_t timerCurrent;
    int MS_PER_FRAME = 2000;
    int lag = 0;
public:

    gameControl(sf::RenderWindow& window):
    window(window),
    objectRenderer(window)
    {}

    void gameLoop();


};



#endif

