#include "../include/Ball.hpp"
#include "../include/GameEngine.hpp"

void Ball::setPosition(const sf::Vector2f &newPosition)
{
    this->sprite.setPosition(newPosition);
}

const sf::Vector2f Ball::getPosition() const
{
    return this->sprite.getPosition();
}

void Ball::setTexture(const std::shared_ptr<sf::Texture> newTexture)
{
    this->sprite.setTexture(*newTexture.get(), true);
}

void Ball::draw(GameEngine *game) const
{
    game->window.draw(sprite);
}

void Ball::setSpeed(const sf::Vector2f &newSpeed)
{
    this->speed = newSpeed;
}

void Ball::move(GameEngine *game)
{
    uint time = game->getElapsedTime();
    sprite.move(speed.x * time, speed.y * time);
    sf::Vector2f pos = getPosition();
    std::cout << pos.x << " " << pos.y << std::endl;
    if (pos.x < 0) {
        speed.x = -speed.x;
        setPosition(sf::Vector2f(0,getPosition().y));
    }
    if (pos.x > game->getVirtualSize().x - sprite.getTextureRect().width) {
        speed.x = -speed.x;
        setPosition(sf::Vector2f(game->getVirtualSize().x - sprite.getTextureRect().width, getPosition().y));
    }

    if (pos.y < 0) {
        speed.y = -speed.y;
        setPosition(sf::Vector2f(getPosition().x, 0));
    }

    if (pos.y > game->getVirtualSize().y - sprite.getTextureRect().width)
    {
        speed.y = -speed.y;
        setPosition(sf::Vector2f(getPosition().x, game->getVirtualSize().y - sprite.getTextureRect().width));
    }
}
