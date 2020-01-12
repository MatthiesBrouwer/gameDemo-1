#include "renderer.hpp"

   std::ifstream & operator>>( std::ifstream &  objectFile, sf::Color & rhs){
        std::string newColor;
        objectFile >> newColor;
        const struct{ const char * name; sf::Color color;} 
        colors[]{
            { "black", sf::Color::Black },
            { "white", sf::Color::White },
            { "red", sf::Color::Red },
            { "green", sf::Color::Green },
            { "blue", sf::Color::Blue },
            { "yellow", sf::Color::Yellow },
            { "magenta", sf::Color::Magenta },
            { "cyan", sf::Color::Cyan },
            { "transparent", sf::Color::Transparent }
        };
        for(auto const & color : colors){
            if( color.name == newColor){
                rhs = color.color;
                return objectFile;
            }
        }


        if( newColor == ""){
            throw endOfFile();
        }
        throw unknownColor(newColor);
    }

    std::ifstream & operator>> ( std::ifstream & objectFile, sf::Vector2f & position){
        char posChar;
        if( ! (objectFile >> posChar)){ throw endOfFile(); }
        if( posChar != '(' ){throw invalidPosition(posChar) ;}

        if( ! ( objectFile >> position.x )){objectFile >>  posChar;throw invalidPosition(posChar);}

        if( ! (objectFile >> posChar)){ throw endOfFile(); }
        if( posChar != ',' ){ throw invalidPosition(posChar) ;}
        
        if( ! ( objectFile >> position.y )){ objectFile >>  posChar;throw invalidPosition(posChar);}

        if( ! (objectFile >> posChar)){ throw endOfFile(); }
        if( posChar != ')' ){ throw invalidPosition(posChar) ;}
        
        return objectFile;
    }

    std::ifstream & operator>> ( std::ifstream & objectFile, int &size){
        if( ! (objectFile >> size)){ throw invalidCircleSize(); }
        return objectFile;
    }





std::shared_ptr<gameObject> objectFromFileIdentifier( std::ifstream & objectFile){
    sf::Vector2f position;
    std::string objectName;
    sf::Color objectColor;
    objectFile >> position >> objectName;
    if( objectName == "CIRCLE"){
        float size;
        objectFile >> objectColor >> size;
        std::shared_ptr<gameObject> newObject(new circle(position, size, objectColor));
        return newObject; 
    }else if(objectName == ""){
        throw endOfFile();
    }

    throw unknownObject( objectName);
}

void renderer::factorObjects(){
    std::ifstream objectFile("objectFile.txt");
    try{
		for(;;){
			auto currentObject = objectFromFileIdentifier(objectFile);
			renderObjectStorage.add( currentObject );
		}
	} catch ( endOfFile ){
	} catch ( std::exception & problem ){
        std::cout<<"Hij vangt exception" << std::endl;
        std::cout<<problem.what()<<std::flush;
	}
}



void renderer::update(){
    for(auto object : renderObjectStorage){
        object->draw(window);
    }
}
