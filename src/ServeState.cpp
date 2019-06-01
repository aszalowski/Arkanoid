#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/ServeState.hpp"
#include "../include/PlayState.hpp"

void ServeState::init(GameEngine *game)
{
    std::cout << "ServeState::init()" << std::endl;
}

void ServeState::cleanup(GameEngine *game)
{
}

void ServeState::pause()
{
}

void ServeState::resume()
{
}

void ServeState::handleEvents(GameEngine *game)
{
    std::cout << "ServeState::handleEvents()" << std::endl;

    uint time = game->getElapsedTime();
    sf::Vector2u virtualSize = game->getVirtualSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        game->p1.move(-1, virtualSize, time);
        game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        game->p1.move(1, virtualSize, time);
        game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        game->p2.move(-1, virtualSize, time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        game->p2.move(1, virtualSize, time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        srand(time);
        float dx = rand() % 400 / 1000.0, dy;
        float oldSpeed = pow(game->ball.getSpeed().x, 2) + pow(game->ball.getSpeed().y, 2);
        dy = -sqrt(oldSpeed -dx * dx);
        std::cout << dy << std::endl;
        rand() % 2 ? dx = -dx : dx = dx;
        game->ball.setSpeed(sf::Vector2f(dx, dy));
        game->popState();
    }
}

void ServeState::update(GameEngine *game)
{
    std::cout << "ServeState::update()" << std::endl;
}

void ServeState::render(GameEngine *game)
{
    std::cout << "ServeState::render()" << std::endl;
    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        i->draw(game);
    }
    game->ball.draw(game);
    game->p1.draw(game);
    game->p2.draw(game);
    game->window.display();
}
