#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class GameEngine;

class Ball : public Object
{
private:
    int whoHit = 0;
    sf::Sprite sprite;
    sf::Vector2f speed;

public:
    Ball() {}
    ~Ball() {}
    void draw(GameEngine *) const;
    void setPosition(const sf::Vector2f &);
    void setSpeed(const sf::Vector2f &);
    const sf::Vector2f getSpeed() const { return speed; };
    void setTexture(const std::string, const sf::IntRect);
    void setTexture(const std::shared_ptr<sf::Texture>);
    const sf::Vector2f getPosition() const;
    void move(GameEngine *);
};

#endif // __OBJECT_HPP__
