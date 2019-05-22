#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

class GameEngine;

class Object{
    public:
        virtual void draw(GameEngine* game) const = 0;
        virtual void setPosition(const sf::Vector2f&) = 0;

        virtual sf::Vector2f getPosition() const = 0;

        virtual ~Object(){}
};




#endif // __OBJECT_HPP__
