#include <iostream>

#include "../include/PlayState.hpp"
#include "../include/ServeState.hpp"

void PlayState::init(GameEngine *game)
{
    std::cout << "PlayState::init()" << std::endl;
    game->ball.setPosition(sf::Vector2f(310, 100));
    game->ball.setSpeed(sf::Vector2f(-0.2, 0.2));
    game->p1.setPosition(sf::Vector2f(100, 300));

    game->ball.setTexture(game->textureMenager.get("ball.png"));
    game->p1.setTexture(game, "breakout_pieces.png", sf::IntRect(48, 72, 64, 16));
    //game->p1.setTexture(game->textureMenager.get("breakout_pieces.png"));
    //game->p1.getSprite().setTextureRect(sf::IntRect(48,72,64,16));

    for (int i = 0; i < 5; i++)
    {
        Block a(1, game->textureMenager.get("block01.png"), sf::Vector2f(100 + i * 40, 100));
        game->blocks.push_back(a);
    }
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
    uint time = game->getElapsedTime();
    sf::Vector2u virtualSize = game->getVirtualSize(); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        game->p1.move(-1, virtualSize, time);
        if(game->ball.objectHit(game->p1.getSprite()))
            game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x - game->ball.getSprite().getGlobalBounds().width - 1, game->ball.getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        game->p1.move(1, virtualSize, time);
        if(game->ball.objectHit(game->p1.getSprite()))
            game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + game->p1.getSprite().getGlobalBounds().width + 1, game->ball.getPosition().y));
    }
}

void PlayState::update(GameEngine *game)
{
    game->ball.moveX(game->getElapsedTime());

    if (game->ball.sideWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(-1, 1);
    }

    if (game->ball.objectHit(game->p1.getSprite()))
    {
        game->ball *= sf::Vector2f(-1, 1);
        game->ball.moveX(game->getElapsedTime());
    }

    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(-1, 1);
            game->ball.moveX(game->getElapsedTime());
            i = game->blocks.erase(i);
            game->p1 += 100;
        }
    }

    game->ball.moveY(game->getElapsedTime());

    if (game->ball.downWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
        game->p1--;
        game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
        game->pushState(ServeState::instance());
    }

    if (game->ball.topWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
    }


    if (game->ball.objectHit(game->p1.getSprite()))
    {
        game->ball *= sf::Vector2f(1, -1);
        game->ball.moveY(game->getElapsedTime());
    }

    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(1, -1);
            game->ball.moveY(game->getElapsedTime());
            i = game->blocks.erase(i);
            game->p1 += 100;
        }
    }
}

void PlayState::render(GameEngine *game)
{
    game->window.clear();
    std::cout << "PlayState::render()" << std::endl;

    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        i->draw(game);
    }

    game->ball.draw(game);
    game->p1.draw(game);
    game->window.display();
}