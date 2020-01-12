#include "gameControl.hpp"



void main(){
    sf::RenderWindow window{ sf::VideoMode{ 1000, 1000 }, "SFML window" };
    gameControl mainGame(window);
    mainGame.gameLoop();

}