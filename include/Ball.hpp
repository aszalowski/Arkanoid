#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"

class GameEngine;

class Ball : public Object
{
private:
    sf::Vector2f position = sf::Vector2f(315, 314);
    sf::Texture texture;
    int whoHit = 0;

public:
    sf::Sprite sprite;
    Ball(sf::Vector2f position);
    Ball();
    ~Ball();
    void draw(GameEngine *game) const;
    void setPosition(const sf::Vector2f &);
    void setTexture(const std::string path, const sf::IntRect rect);
    void setTexture(const sf::Texture *texture);
    sf::Texture& getTexture(){ return texture; }
    sf::Vector2f getPosition() const;
};

#endif // __OBJECT_HPP__
