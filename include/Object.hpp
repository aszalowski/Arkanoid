#ifndef __OBJECT_HPP__
#define __OBJECT_HPP__

class GameEngine;

class Object
{
public:
    virtual void draw(GameEngine *) const = 0;

    virtual const sf::Vector2f getPosition() const = 0; // NOTE: where are sfml and std linked
    virtual void setPosition(const sf::Vector2f &) = 0;

    virtual void setTexture(const std::shared_ptr<sf::Texture>) = 0;

    virtual ~Object() {}
};

#endif // __OBJECT_HPP__
