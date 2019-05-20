#include "../include/Player.hpp"

Player::Player(int index, sf::Vector2f Position, sf::Texture texture, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start, int hp, int score)
{
    this->index = index;
    this->hp = hp;
    this->score = score;
    this->setPosition(Position);
    this->texture = texture;
    this->setControls(left, right, start);
}

sf::Vector2f Player::getPosition()
{
    return this->position;
}

void Player::setPosition(sf::Vector2f Position)
{
    this->position = Position;
}

void Player::setControls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start)
{
    this->controls.left = left;
    this->controls.right = right;
    this->controls.start = start;
}