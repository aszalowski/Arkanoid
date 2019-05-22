#include "../include/Ball.hpp"
#include "../include/GameEngine.hpp"

Ball::Ball()
{
    this->sprite.setTexture(texture);
}

Ball::Ball(sf::Vector2f position)
{
    this->position = position;
    this->sprite.setTexture(texture);
}

Ball::~Ball()
{
}

void Ball::setPosition(const sf::Vector2f &position)
{
    this->position = position;
}

sf::Vector2f Ball::getPosition() const
{
    return this->position;
}

void Ball::setTexture(const std::string path, const sf::IntRect rect)
{
    this->texture.loadFromFile(path, rect);
    this->sprite.setTexture(this->texture);
}

void Ball::setTexture(const sf::Texture* texture){
    this->texture.update(*texture);
    this->sprite.setTexture(this->texture);
}


void Ball::draw(GameEngine *game) const
{
    game->window.draw(sprite);
}
