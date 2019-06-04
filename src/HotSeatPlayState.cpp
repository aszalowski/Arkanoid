#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#include "../include/HotSeatPlayState.hpp"
#include "../include/P2ServeState.hpp"
#include "../include/EndGameState.hpp"

void HotSeatPlayState::init(GameEngine *game)
{
    std::cout << "HotSeat::init()" << std::endl;
    game->p2.setPosition(sf::Vector2f(100, 20));
    game->p2.setHp(3);
    game->p2.active = true;

    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(20)).setSmooth(false);

    for(uint i = 0; i < game->p2.getHp(); i++){
        sf::Sprite newHeart(*game->textureMenager.get("breakout_pieces.png").get(), sf::IntRect(120, 135, 10, 8));
        newHeart.scale(sf::Vector2f(2, 2));
        newHeart.setPosition(sf::Vector2f(game->getVirtualSize().x - (i+1)*newHeart.getGlobalBounds().width - i*5, 3));
        hearts.push_back(newHeart);
    }
    score.setFont(*font);
    score.setCharacterSize(20);
    score.setString("Points: 0");
    score.setPosition(0, 0);




    PlayState::init(game);
}

void HotSeatPlayState::cleanup(GameEngine *game)
{
    hearts.clear();
}

void HotSeatPlayState::pause()
{
}

void HotSeatPlayState::resume()
{
}

void HotSeatPlayState::handleEvents(GameEngine *game, sf::Event event)
{

    PlayState::handleEvents(game, event);
}

void HotSeatPlayState::update(GameEngine *game)
{

    if(game->p2.getHp() == 0)
        game->pushState(EndGameState::instance());
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
        game->p2--;
        hearts.pop_back();
        if(game->p2.getHp() != 0)
            game->pushState(P2ServeState::instance());
    }

    if (game->ball.objectHit(game->p2.getSprite()))
    {
        game->ball.whoHit = p2;
        game->ball *= sf::Vector2f(1, -1);
        game->ball.moveY(game->getElapsedTime());
    }

    score.setString("Points: " + std::to_string(game->p2.getScore()));

    PlayState::update(game);
}

void HotSeatPlayState::render(GameEngine *game)
{
    for(auto heart : hearts)
        game->window.draw(heart);
    
    game->window.draw(score);

    game->p2.draw(game);
    PlayState::render(game);
}
