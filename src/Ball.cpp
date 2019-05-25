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

void Ball::moveX(uint time)
{
    sprite.move(speed.x * time, 0);
}

void Ball::moveY(uint time)
{
    sprite.move(0, speed.y * time);
}

bool Ball::sideWindowHit(sf::Vector2u virtualSize)
{
    sf::Vector2f pos = getPosition();
    return (pos.x > virtualSize.x - sprite.getTextureRect().width || pos.x < 0) ? 1 : 0;
}
bool Ball::downWindowHit(sf::Vector2u virtualSize)
{
    return (getPosition().y > virtualSize.y - sprite.getTextureRect().height) ? 1 : 0;
}
bool Ball::topWindowHit(sf::Vector2u virtualSize)
{
    return (getPosition().y < 0) ? 1 : 0;
}

bool Ball::playerHit(const sf::Sprite &player)
{
    return Collision::PixelPerfectTest(player, sprite) ? 1 : 0;
}
bool Ball::playerTopHit(const sf::Sprite &player)
{
    sf::Vector2f pos = getPosition();
    if (pos.y + sprite.getTextureRect().height > player.getPosition().y && pos.y < player.getPosition().y + player.getTextureRect().height)
    {

        return 1;
    }
    else
    {
        return 0;
    }
}

Ball* Ball::operator*=(sf::Vector2f &reverse)
{
    speed.x *= reverse.x;
    speed.y *= reverse.y;
    return this;

}
