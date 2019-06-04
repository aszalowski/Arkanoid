#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"

class GameEngine;

struct Controls /// Controls for the player - movement and serve
{
    sf::Keyboard::Key left, right, start;
    Controls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start) : left(left), right(right), start(start){};
};
/// Class of a paddle
class Player : public Object
{
private:
    int index;
    int hp = 3;
    uint score = 0;
    Controls controls;
    sf::Sprite sprite;
    float moveStep = 0.5;

public:
    Player(int index, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start) : index(index), controls(left, right, start){};
    ~Player() {}
    const sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f &);
    void setControls(sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key);
    void setTexture(std::shared_ptr<sf::Texture>);
    void setTexture(GameEngine *, std::string, sf::IntRect);
    void setScore(const uint &newScore) { score = newScore; }
    uint getScore() { return score; }
    uint getHp() { return hp; }
    void setHp(int newHp) { hp = newHp; }
    const sf::Sprite &getSprite() const { return sprite; }
    sf::Sprite &modifySprite() { return sprite; }
    const uint getScore() const { return score; }
    const float getMoveStep() const { return moveStep; }
    void setMoveStep(float &newStep) { moveStep = newStep; }
    void operator+=(uint points) { score += points; } ///< Adds score
    Player operator--(int);                           ///< Descreses health points

    void move(int side, sf::Vector2u, uint);

    void draw(GameEngine *game) const;

    bool active = false;
};

#endif