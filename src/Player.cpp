#include "../include/Player.hpp"
#include "../include/GameEngine.hpp"

Player::Player(int index, sf::Vector2f Position, sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start, int hp, int score)
{
    this->index = index;
    this->hp = hp;
    this->score = score;
    this->setPosition(Position);
    this->setControls(left, right, start);
}

Player::~Player(){}

void Player::setTexture(sf::Texture *newTexture)
{
    sprite.setTexture(*newTexture);
}
void Player::setTexture(std::string path, sf::IntRect rect)
{
    texture.loadFromFile(path, rect);
    sprite.setTexture(texture);
}

sf::Vector2f Player::getPosition() const
{
    return this->position;
}

void Player::setPosition(const sf::Vector2f &Position)
{
    this->position = Position;
}

void Player::setControls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start)
{
    this->controls.left = left;
    this->controls.right = right;
    this->controls.start = start;
}

void Player::draw(GameEngine *game) const
{
    game->window.draw(this->sprite);
}