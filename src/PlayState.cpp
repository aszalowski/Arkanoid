#include <iostream>

#include "../include/PlayState.hpp"
#include "../include/ServeState.hpp"
#include "../include/PauseState.hpp"

void PlayState::init(GameEngine *game)
{
    std::cout << "PlayState::init()" << std::endl;
    game->ball.setPosition(sf::Vector2f(300, 270));
    game->ball.setSpeed(sf::Vector2f(0.2, -0.2));
    game->p1.setPosition(sf::Vector2f(300, 320));

    game->ball.setTexture(game->textureMenager.get("ball.png"));

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

void PlayState::handleEvents(GameEngine *game, sf::Event event)
{
    if(event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game->pushState(PauseState::instance());
}

void PlayState::update(GameEngine *game)
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

    game->ball.moveX(time);

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

    game->ball.moveY(time);

    if (game->ball.downWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
        game->p1--;
        //TODO: Add life check and gameover
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
    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        i->draw(game);
    }

    sf::Font font;
    if (!font.loadFromFile("resources/pixel.ttf"))
    {
        std::cout << "ERORR loading font" << std::endl;
        return;
    }

    // sf::Text p1Life("Lifes left: " + std::to_string(game->p1.getHp()), font, 20);
    // p1Life.setPosition(0, 0);
    // sf::Text p1Points("Score: " + std::to_string(game->p1.getScore()), font, 20);
    // p1Points.setPosition(500, 0);
    // game->window.draw(p1Points);
    // game->window.draw(p1Life);

    game->ball.draw(game);
    game->p1.draw(game);
}