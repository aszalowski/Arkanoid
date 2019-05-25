#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(GameEngine *game)
{
    std::cout << "PlayState::init()" << std::endl;
    game->ball.setPosition(sf::Vector2f(232, 5));
    game->ball.setSpeed(sf::Vector2f(-0.1, 0.1));
    game->p1.setPosition(sf::Vector2f(100, 100));


}

void PlayState::cleanup(GameEngine *game)
{
}

void PlayState::pause()
{
}

void PlayState::resume()
{
}

void PlayState::handleEvents(GameEngine *game)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        game->p1.move(-1, game);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        game->p1.move(1, game);
}

void PlayState::update(GameEngine *game)
{
    /*
    bool playerHit = false;
    game->ball.moveX(game->getElapsedTime());
    if (game->ball.sideWindowHit(game->getVirtualSize()))
    {
        game->ball.setSpeed(sf::Vector2f(-game->ball.getSpeed().x, game->ball.getSpeed().y));
        std::cout << "window side hit" << std::endl;
    }

    if (Collision::PixelPerfectTest(game->ball.getSprite(), game->p1.getSprite()))
    {
        game->ball.setSpeed(sf::Vector2f(-game->ball.getSpeed().x, game->ball.getSpeed().y));
        std::cout << "player side hit" << std::endl;
    }


    game->ball.moveY(game->getElapsedTime());
    if (game->ball.downWindowHit(game->getVirtualSize()) || game->ball.topWindowHit(game->getVirtualSize()))
    {
        game->ball.setSpeed(sf::Vector2f(game->ball.getSpeed().x, -game->ball.getSpeed().y));
        std::cout << "window top/bottom hit" << std::endl;
    }

    if (game->ball.playerHit(game->p1.getSprite()))
    {
        game->ball.setSpeed(sf::Vector2f(game->ball.getSpeed().x, -game->ball.getSpeed().y));
        std::cout << "player top/bottom hit" << std::endl;
    }
    */
}

void PlayState::render(GameEngine *game)
{
    std::shared_ptr<sf::Texture> b = std::make_shared<sf::Texture>();
    b.get()->loadFromFile("resources/ball.png", sf::IntRect(0, 0, 5, 5));
    game->ball.setTexture(b);

    std::shared_ptr<sf::Texture> p = std::make_shared<sf::Texture>();
    p.get()->loadFromFile("resources/breakout_pieces.png", sf::IntRect(8, 8, 32, 16));
    game->p1.setTexture(p);

    game->ball.moveX(game->getElapsedTime());
    if (game->ball.sideWindowHit(game->getVirtualSize()))
    {
        game->ball.setSpeed(sf::Vector2f(-game->ball.getSpeed().x, game->ball.getSpeed().y));
        std::cout << "window side hit" << std::endl;
    }

    if (game->ball.playerHit(game->p1.getSprite()))
    {
        std::cout << "player side hit" << std::endl;
        game->ball.setSpeed(sf::Vector2f(-game->ball.getSpeed().x, game->ball.getSpeed().y));
        game->ball.moveX(game->getElapsedTime());
    }

    game->ball.moveY(game->getElapsedTime());
    if (game->ball.downWindowHit(game->getVirtualSize()) || game->ball.topWindowHit(game->getVirtualSize()))
    {
        std::cout << "window top/bottom hit" << std::endl;
        game->ball.setSpeed(sf::Vector2f(game->ball.getSpeed().x, -game->ball.getSpeed().y));
    }

    if (game->ball.playerHit(game->p1.getSprite()))
    {
        std::cout << "player top/bottom hit" << std::endl;
        game->ball.setSpeed(sf::Vector2f(game->ball.getSpeed().x, -game->ball.getSpeed().y));
        game->ball.moveY(game->getElapsedTime());
    }

    game->window.clear();
    std::cout << "PlayState::render()" << std::endl;
    game->ball.draw(game);
    game->p1.draw(game);
    game->window.display();
}