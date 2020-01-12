#ifndef _RENDERER_HPP
#define _RENDERER_HPP

#include "gameObject.hpp" 
#include <algorithm>
#include <vector>
#include "memory"
#include "string.h"
#include <fstream>
#include "exceptions.hpp"
#include "objectStorage.hpp"
#include "circle.hpp"

class renderer{
private:
    sf::RenderWindow& window;
    objectStorage<10> renderObjectStorage;
public:
    renderer(sf::RenderWindow& window):
        window(window)
    {}


    void update();
    //void renderObjects();
    void factorObjects();
    std::shared_ptr<gameObject> getCurrentMainObject(){return renderObjectStorage.begin();}


};
#endif