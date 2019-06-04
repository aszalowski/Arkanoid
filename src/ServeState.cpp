#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/ServeState.hpp"
#include "../include/PlayState.hpp"
#include "../include/PauseState.hpp"

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

void ServeState::handleEvents(GameEngine *game, sf::Event event)
{
    std::cout << "ServeState::handleEvents()" << std::endl;
    if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game->pushState(PauseState::instance());

}

void ServeState::update(GameEngine *game)
{
    std::cout << "ServeState::update()" << std::endl;
    uint lastFrameTime = game->getElapsedTime();
    sf::Vector2u virtualSize = game->getVirtualSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        game->p1.move(-1, virtualSize, lastFrameTime);
        game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        game->p1.move(1, virtualSize, lastFrameTime);
        game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        game->p2.move(-1, virtualSize, lastFrameTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        game->p2.move(1, virtualSize, lastFrameTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        srand(time(nullptr));
        float dx = 0.1 + rand() % 150 / 1000.0, dy;
        std::cout<<dx<<std::endl;
        float oldSpeed = pow(game->ball.getSpeed().x, 2) + pow(game->ball.getSpeed().y, 2);
        dy = -sqrt(fabs(oldSpeed -dx * dx));
        std::cout << dy << std::endl;
        rand() % 2 ? dx = -dx : dx = dx;
        game->ball.setSpeed(sf::Vector2f(dx, dy));
        game->popState();
    }
}

void ServeState::render(GameEngine *game)
{
    std::cout << "ServeState::render()" << std::endl;
}
