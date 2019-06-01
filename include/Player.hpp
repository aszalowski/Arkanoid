#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"

class GameEngine;

struct Controls
{
    sf::Keyboard::Key left, right, start;
    Controls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start) : left(left), right(right), start(start){};
};

class Player : public Object
{
private:
    int index;
    int hp = 3;
    uint score = 0;
    sf::Sprite sprite;
    Controls controls;

public:
    Player(int index, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start) : index(index), controls(left, right, start){};
    ~Player(){}
    const sf::Vector2f& getPosition() const;
    void setPosition(const sf::Vector2f &);
    void setControls(sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key);
    void setTexture(std::shared_ptr<sf::Texture>);
    void setTexture(std::string, sf::IntRect);
    void setScore(const uint &newScore) { score = newScore; }
    sf::Sprite& modifySprite(){ return sprite; }
    const uint getScore() const { return score; }
    void operator+=(uint points) { score += points; };

    void draw(GameEngine *game) const;
};

#endif