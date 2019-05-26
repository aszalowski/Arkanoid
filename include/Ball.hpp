#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"
#include "Collision.hpp"

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
    void setTexture(GameEngine *, std::string, sf::IntRect);
    void setTexture(const std::shared_ptr<sf::Texture>);
    const sf::Vector2f getPosition() const;
    const sf::Sprite &getSprite() const { return sprite; }
    sf::Sprite &modifySprite() { return sprite; }
    void moveX(uint);
    void moveY(uint);
    bool sideWindowHit(sf::Vector2u);
    bool downWindowHit(sf::Vector2u);
    bool topWindowHit(sf::Vector2u);
    bool objectHit(const sf::Sprite &);
    Ball operator*=(sf::Vector2f);
};

#endif // __BALL_HPP__
