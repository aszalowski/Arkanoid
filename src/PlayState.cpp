#include <iostream>
#include <ctime>

#include "../include/PlayState.hpp"
#include "../include/ServeState.hpp"
#include "../include/PauseState.hpp"
#include "../include/EndGameState.hpp"
#include "../include/LevelGenerator.hpp"

void PlayState::init(GameEngine *game)
{
    std::cout << "PlayState::init()" << std::endl;

    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(20)).setSmooth(false);


    game->ball.setPosition(sf::Vector2f(300, 270));
    game->ball.setSpeed(sf::Vector2f(0.2, -0.2));
    game->p1.setPosition(sf::Vector2f(300, 320));
    game->p1.setHp(3);

    for(uint i = 0; i < game->p1.getHp(); i++){
        sf::Sprite newHeart(*game->textureMenager.get("breakout_pieces.png").get(), sf::IntRect(120, 135, 10, 8));
        newHeart.scale(sf::Vector2f(2, 2));
        newHeart.setPosition(sf::Vector2f(game->getVirtualSize().x - (i+1)*newHeart.getGlobalBounds().width - i*5, game->getVirtualSize().y - newHeart.getGlobalBounds().height - 3));
        hearts.push_back(newHeart);
    }
    score.setFont(*font);
    score.setCharacterSize(20);
    score.setString("Points: 0");
    score.setPosition(0, game->getVirtualSize().y - score.getGlobalBounds().height - 5);

    LevelGenerator::generateLevel(game);
}

void PlayState::cleanup(GameEngine *game)
{
    game->blocks.clear();
    hearts.clear();
}

void PlayState::pause()
{
}

void PlayState::resume()
{
}

void PlayState::handleEvents(GameEngine *game, sf::Event event)
{
    if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game->pushState(PauseState::instance());
}

void PlayState::update(GameEngine *game)
{
    if(game->blocks.empty() || game->p1.getHp() == 0)
        game->pushState(EndGameState::instance());

    uint lastFrameTime = game->getElapsedTime();

    sf::Vector2u virtualSize = game->getVirtualSize();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        game->p1.move(-1, virtualSize, lastFrameTime);
        if (game->ball.objectHit(game->p1.getSprite()))
            game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x - game->ball.getSprite().getGlobalBounds().width - 1, game->ball.getPosition().y));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        game->p1.move(1, virtualSize, lastFrameTime);
        if (game->ball.objectHit(game->p1.getSprite()))
            game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + game->p1.getSprite().getGlobalBounds().width + 1, game->ball.getPosition().y));
    }

    game->ball.moveX(lastFrameTime);

    if (game->ball.sideWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(-1, 1);
    }

    if (game->ball.objectHit(game->p1.getSprite()))
    {
        game->ball.whoHit = p1;
        game->ball *= sf::Vector2f(-1, 1);
        game->ball.moveX(game->getElapsedTime());
    }

    for (std::list<Block>::iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(-1, 1);
            game->ball.moveX(game->getElapsedTime());
            uint hp = i->getHp();
            std::cout<< "here" << std::endl;
            if (hp == 1){
                std::cout<< "hp == 1" << std::endl;
                i = game->blocks.erase(i);
            }
            else
            {
                std::cout<< "hp != 1" << std::endl;
                --(*i);
            }
            std::cout<< "after" << std::endl;
            (game->ball.whoHit == p1) ? game->p1 += 100 : game->p2 += 100;
        }
    }

    game->ball.moveY(lastFrameTime);

    if (game->ball.downWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
        game->p1--;
        hearts.pop_back();
        if(game->p1.getHp() != 0){
            //TODO: Add life check and gameover
            game->ball.setPosition(sf::Vector2f(game->p1.getPosition().x + (game->p1.getSprite().getTextureRect().width - game->ball.getSprite().getTextureRect().width) / 2, game->p1.getPosition().y - game->ball.getSprite().getTextureRect().height));
            game->pushState(ServeState::instance());
            return;
        }
    }

    if (game->ball.topWindowHit(game->getVirtualSize()))
    {
        game->ball *= sf::Vector2f(1, -1);
    }

    if (game->ball.objectHit(game->p1.getSprite()))
    {
        game->ball.whoHit = p1;
        game->ball *= sf::Vector2f(1, -1);
        game->ball.moveY(game->getElapsedTime());
    }

    for (std::list<Block>::iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        if (game->ball.objectHit(i->getSprite()))
        {
            game->ball *= sf::Vector2f(1, -1);
            game->ball.moveY(game->getElapsedTime());
            uint hp = i->getHp();
            std::cout<< "here" << std::endl;
            if (hp == 1){
                std::cout<< "hp == 1" << std::endl;
                i = game->blocks.erase(i);
            }
            else
            {
                std::cout<< "hp != 1" << std::endl;
                --(*i);
            }
            std::cout<< "after" << std::endl;
            (game->ball.whoHit == p1) ? game->p1 += 100 : game->p2 += 100;
            score.setString("Points: " + std::to_string(game->p1.getScore()));
        }
    }
}

void PlayState::render(GameEngine *game)
{
    for (std::list<Block>::const_iterator i = game->blocks.begin(); i != game->blocks.end(); ++i)
    {
        i->draw(game);
    }

    for(auto heart : hearts)
        game->window.draw(heart);
    
    game->window.draw(score);


    game->ball.draw(game);
    game->p1.draw(game);
}
