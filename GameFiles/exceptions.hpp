#ifndef _EXCEPTIONS_HPP
#define _EXCEPTIONS_HPP
#include <iostream>
#include <string.h>

class endOfFile : public std::exception{
private:
    std::string exceptionMessage;
public:
    endOfFile(){
        exceptionMessage = "End of file reached";
    }
    const char * what(){
        return exceptionMessage.c_str();
    }
};


class unknownObject : public std::exception{
private:
    std::string exceptionMessage;
public:
    unknownObject( std::string objectName):
            exceptionMessage{"Unknown objectname found[" + objectName + "]"}
    {}
    const char * what() {
        return exceptionMessage.c_str();
    }
};

class unknownColor : public std::exception{
private:
    std::string exceptionMessage;
public:
    unknownColor( std::string colorName):
        exceptionMessage{"Unknown color found[" + colorName + "]"}
    {}
    const char * what() {
        return exceptionMessage.c_str();
    }
};

class invalidPosition : public std::exception{
private:
    std::string exceptionMessage;
public:
    invalidPosition( char posChar):
        exceptionMessage{"Invalid position found due to [" + std::string(1, posChar) + "]"}
    {}
    const char * what() {
        return exceptionMessage.c_str();
    }
};

class invalidCircleSize : public std::exception{
private:
    std::string exceptionMessage;
public:
    invalidCircleSize():
        exceptionMessage{"Invalid Circle Size found"}
    {}
    const char * what() {
        return exceptionMessage.c_str();
    }
};

class invalidFilename : public std::exception{
private:
    std::string exceptionMessage;
public:
    invalidFilename():
        exceptionMessage{"Invalid Filename found"}
    {}
    const char * what(){
        return exceptionMessage.c_str();
    }
};








#endif