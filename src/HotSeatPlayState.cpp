#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/HotSeatPlayState.hpp"
#include "../include/P2ServeState.hpp"

void HotSeatPlayState::init(GameEngine *game)
{
    std::cout << "HotSeat::init()" << std::endl;
    game->p2.setPosition(sf::Vector2f(100, 20));
    std::cout << game->p2.getSprite().getPosition().x << ',' << game->p2.getSprite().getPosition().x<<std::endl;
    PlayState::init(game);
}

void HotSeatPlayState::cleanup(GameEngine *game)
{
}

void HotSeatPlayState::pause()
{
}

void HotSeatPlayState::resume()
{
}

void HotSeatPlayState::handleEvents(GameEngine *game, sf::Event event)
{
    std::cout << "HotSeat::handleEvents()" << std::endl;

    PlayState::handleEvents(game, event);
}

void HotSeatPlayState::update(GameEngine *game)
{
    std::cout << "HotSeat::update()" << std::endl;

    uint time = game->getElapsedTime();
    sf::Vector2u virtualSize = game->getVirtualSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        game->p2.move(-1, virtualSize, time);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        game->p2.move(1, virtualSize, time);

    if (game->ball.topWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
        game->ball.setPosition(sf::Vector2f(game->p2.getPosition().x + (game->p2.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p2.getPosition().y + game->ball.getSprite().getTextureRect().height));
        game->pushState(P2ServeState::instance());
    }

    if (game->ball.objectHit(game->p2.getSprite()))
    {
        game->ball.whoHit = p2;
        game->ball *= sf::Vector2f(1, -1);
        game->ball.moveY(game->getElapsedTime());
    }
    PlayState::update(game);
}

void HotSeatPlayState::render(GameEngine *game)
{
    std::cout << "HotSeat::render()" << std::endl;
    game->p2.draw(game);
    PlayState::render(game);
}
