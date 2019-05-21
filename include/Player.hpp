#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>

typedef struct
{
    sf::Keyboard::Key left, right, start;
} Controls;

class Player
{
private:
    int index;
    int hp;
    int score;
    sf::Texture texture;
    sf::Vector2f position;
    Controls controls;

public:
    Player(int, sf::Vector2f, sf::Keyboard::Key, sf::Keyboard::Key, sf::Keyboard::Key, int hp = 3, int score = 0);
    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f);
    void setControls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start);
    void setTexture(sf::Texture newTexture){texture.update(newTexture);}
    sf::Texture getTexture(){return texture;}
};

#endif