#include "gameControl.hpp"

void gameControl::gameLoop(){

	objectRenderer.factorObjects();


    while (window.isOpen()) {

		time(&timerCurrent);
		auto elapsed = timerCurrent - timerPrevious;
		timerPrevious = timerCurrent;
		lag += elapsed;
		
	

		command* newCommand = gameInputHandler.handleInput(objectRenderer.getCurrentMainObject());
		if(newCommand){
			newCommand->execute();
		}
		delete newCommand;

		while(lag >= MS_PER_FRAME){

			lag -= MS_PER_FRAME;
		}


        window.clear();
        objectRenderer.update();
		window.display();

        sf::Event event;		
	    while( window.pollEvent(event) ){
			if( event.type == sf::Event::Closed ){
				window.close();
			}
		}
       
	}
}