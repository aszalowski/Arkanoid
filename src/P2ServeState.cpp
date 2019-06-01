#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/P2ServeState.hpp"
#include "../include/PlayState.hpp"

void P2ServeState::init(GameEngine *game)
{
    std::cout << "P2ServeState::init()" << std::endl;
    ServeState::init(game);
}

void P2ServeState::cleanup(GameEngine *game)
{
    ServeState::cleanup(game);
}

void P2ServeState::pause()
{
    ServeState::pause();
}

void P2ServeState::resume()
{
    ServeState::resume();
}

void P2ServeState::handleEvents(GameEngine *game, sf::Event event)
{
    std::cout << "P2ServeState::handleEvents()" << std::endl;

    uint time = game->getElapsedTime();
    sf::Vector2u virtualSize = game->getVirtualSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        game->p2.move(-1, virtualSize, time);
        game->ball.setPosition(sf::Vector2f(game->p2.getPosition().x + (game->p2.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p2.getPosition().y + game->p2.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        game->p2.move(1, virtualSize, time);
        game->ball.setPosition(sf::Vector2f(game->p2.getPosition().x + (game->p2.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p2.getPosition().y + game->p2.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        game->p1.move(-1, virtualSize, time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        game->p1.move(1, virtualSize, time);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        srand(time);
        float dx = rand() % 400 / 1000.0, dy;
        float oldSpeed = pow(game->ball.getSpeed().x, 2) + pow(game->ball.getSpeed().y, 2);
        dy = -sqrt(oldSpeed - dx * dx);
        std::cout << dy << std::endl;
        rand() % 2 ? dx = -dx : dx = dx;
        game->ball.setSpeed(sf::Vector2f(dx, dy));
        game->popState();
    }
    
}

void P2ServeState::update(GameEngine *game)
{
    std::cout << "P2ServeState::update()" << std::endl;
}

void P2ServeState::render(GameEngine *game)
{
    std::cout << "P2ServeState::render()" << std::endl;
    game->p2.draw(game);
    ServeState::render(game);
}
