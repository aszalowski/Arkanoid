#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include "Object.hpp"

class Button: public Object{
    public:
        Button(sf::Texture normal, sf::Texture clicked);


    private:
        sf::Sprite normal;
        sf::Sprite clicked;

};


#endif // __BUTTON_HPP__
