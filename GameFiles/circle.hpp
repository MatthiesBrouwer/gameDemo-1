#ifndef _CIRCLE_HPP
#define _CIRCLE_HPP
#include <SFML/Graphics.hpp>
#include "gameObject.hpp"


class circle : virtual public gameObject{
public:

	circle( sf::Vector2f position, float size, sf::Color objectColor):
	    position( position ),
	    size( size ),
	    objectColor(objectColor){
            objectCircle = sf::CircleShape(size);
            objectCircle.setFillColor(objectColor);
    };
	~circle(){}

	void move( sf::Vector2f delta) override{
        position+= delta;
    };
	void draw( sf::RenderWindow & window ) override{
        window.draw(objectCircle);
    };

private:
	sf::Vector2f position;
	float size;
	sf::Color objectColor;
	sf::CircleShape objectCircle;
};

#endif
