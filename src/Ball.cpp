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

void Ball::move(GameEngine* game)
{
    std::cout << game->ball.sprite.getPosition().x << std::endl;
    if((game->ball.sprite.getPosition().x <= (game->window.getSize().x - game->ball.sprite.getTextureRect().width)) ){
        int time = game->Clock.getElapsedTime().asMilliseconds();
        game->ball.sprite.move(speed.x * time, speed.y * time);
        //std::cout<<(game->ball.sprite.getPosition().x <= (game->window.getSize().x - game->ball.sprite.getTextureRect().width))<<std::endl;
    }
}
