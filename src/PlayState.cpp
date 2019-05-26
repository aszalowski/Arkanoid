#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(GameEngine *game)
{
    std::cout << "PlayState::init()" << std::endl;
    game->ball.setPosition(sf::Vector2f(310, 100));
    game->ball.setSpeed(sf::Vector2f(-0.2, 0));
    game->p1.setPosition(sf::Vector2f(100, 300));

    game->ball.setTexture(game->textureMenager.get("ball.png"));
    game->p1.setTexture(game->textureMenager.get("paddle.png"));

    for (int i = 0; i < 5; i++)
    {
        char c = i + 48;
        std::string name = "block0";
        name += c;
        name += ".png";
        Block a(1, game->textureMenager.get(name), sf::Vector2f(100 + i * 40, 100));
        blocks.push_back(a);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        game->p1.move(-1, game);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        game->p1.move(1, game);
}

void PlayState::update(GameEngine *game)
{
    game->ball.moveX(game->getElapsedTime());
    std::cout << game->ball.getPosition().x << std::endl;
    if (game->ball.sideWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(-1, 1);
    }

    if (game->ball.objectHit(game->p1.getSprite()))
    {
        game->ball *= sf::Vector2f(-1, 1);
        game->ball.moveX(game->getElapsedTime());
    }

    for (std::vector<Block>::const_iterator i = blocks.begin(); i != blocks.end(); )
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(-1, 1);
            game->ball.moveX(game->getElapsedTime());
            blocks.erase(i);
            game->p1 += 100;
        }
        else{
            ++i;
        }
    }

    game->ball.moveY(game->getElapsedTime());
    if (game->ball.downWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
        //game->p1--;
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

    for (std::vector<Block>::const_iterator i = blocks.begin(); i != blocks.end(); ++i)
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(1, -1);
            game->ball.moveY(game->getElapsedTime());
            blocks.erase(i);
            game->p1 += 100;
        }
    }
}

void PlayState::render(GameEngine *game)
{
    game->window.clear();
    std::cout << "PlayState::render()" << std::endl;

    for (std::vector<Block>::const_iterator i = blocks.begin(); i != blocks.end(); ++i)
    {
        i->draw(game);
    }
    game->ball.draw(game);
    game->p1.draw(game);
    game->window.display();
}