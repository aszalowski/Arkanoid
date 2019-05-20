#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include "GameEngine.hpp"

class Object{
    public:
        virtual void draw(GameEngine* game) const = 0;
        virtual void setPosition(const sf::Vector2f&) = 0;

        virtual sf::Vector2f getPosition() const = 0;

        virtual ~Object() = 0;
};

#endif // __OBJECT_HPP__