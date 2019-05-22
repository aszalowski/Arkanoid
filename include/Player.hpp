#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include "Object.hpp"
class GameEngine;

typedef struct
{
    sf::Keyboard::Key left, right, start;
} Controls;

class Player : public Object
{
private:
    int index;
    int hp;
    int score;
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    Controls controls;

public:
    Player(int, sf::Vector2f, sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key, int hp = 3, int score = 0);
    ~Player();
    sf::Vector2f getPosition() const;
    void setPosition(const sf::Vector2f &);
    void setControls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start);
    void setTexture(sf::Texture *newTexture);
    void setTexture(std::string path, sf::IntRect rect);
    sf::Texture& getTexture() { return texture; }

    void draw(GameEngine *game) const ;
};

#endif