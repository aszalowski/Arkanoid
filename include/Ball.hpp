#ifndef __BALL_HPP__
#define __BALL_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"
#include "Collision.hpp"

class GameEngine;

enum HitBy 
{
    p1 = 1,
    p2 = 2
};
///Class of ball
class Ball : public Object 
{
private:
    sf::Sprite sprite; ///< Drawable representation of a texture, with its own transformations, color, etc.
    sf::Vector2f speed; ///< Vector of speed

public:
    HitBy whoHit; ///< Stores information, which player hit the ball
    Ball() {} ///< Default ball constructor
    ~Ball() {} ///< Default ball destructor
    void draw(GameEngine *) const; 
    void setPosition(const sf::Vector2f &);
    void setSpeed(const sf::Vector2f &);
    const sf::Vector2f getSpeed() const { return speed; };
    void setTexture(GameEngine *, std::string, sf::IntRect);
    void setTexture(const std::shared_ptr<sf::Texture>);
    void setTexture(const std::shared_ptr<sf::Texture>, sf::IntRect);
    const sf::Vector2f getPosition() const;
    sf::Sprite &getSprite() { return sprite; }
    sf::Sprite &modifySprite() { return sprite; }
    void moveX(uint); ///< Moves ball in X-axis based on the time of rendering the frame (eliminates lagging, when framerate drops)
    void moveY(uint); ///< Moves ball in Y-axis based on the time of rendering the frame (eliminates lagging, when framerate drops)
    bool sideWindowHit(sf::Vector2u); ///< Checking if ball hit side of the screen
    bool downWindowHit(sf::Vector2u); ///< Checking if ball hit bottom of the screen
    bool topWindowHit(sf::Vector2u);  ///< Checking if ball hit top of the screen
    bool objectHit(const sf::Sprite &); ///< Check collision with objects like Blocks and Players(paddles)
    Ball operator*=(sf::Vector2f); ///< Changes the ball speed by multiplying vectors (a,b) * (c,d) = (a*c, b*d)
};

#endif // __BALL_HPP__
