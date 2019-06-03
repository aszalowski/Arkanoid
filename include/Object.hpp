#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

#include <memory>

class GameEngine;

/**
 * Abstract class used than for all objects
 * */
class Object
{
public:
    virtual void draw(GameEngine *) const = 0; ///< Drawing object on the screen

    virtual const sf::Vector2f getPosition() const = 0; // NOTE: where are sfml and std linked
    virtual void setPosition(const sf::Vector2f &) = 0;

    // NOTE delete as some object don't have a single texture e.g. Button
    //virtual void setTexture(const std::shared_ptr<sf::Texture>) = 0;

    virtual ~Object() {}
};

#endif // __OBJECT_HPP__
