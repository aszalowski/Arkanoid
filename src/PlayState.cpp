#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(GameEngine *game){
    std::cout << "PlayState::init()" << std::endl;
    game->ball.setPosition(sf::Vector2f(100,100));
    game->ball.setSpeed(sf::Vector2f(0.2, -0.2));
    game->p1.setPosition(sf::Vector2f(200,200));

}

void PlayState::cleanup(GameEngine *game){

}

void PlayState::pause(){

}

void PlayState::resume()
{
}

void PlayState::handleEvents(GameEngine* game){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        game->p1.move(-1, game);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        game->p1.move(1, game);
}

void PlayState::update(GameEngine* game){

}

void PlayState::render(GameEngine* game){
    game->window.clear();
    std::shared_ptr<sf::Texture> b = std::make_shared<sf::Texture>();
    b.get()->loadFromFile("resources/ball.png", sf::IntRect(0, 0, 20, 20));
    game->ball.setTexture(b);
    std::shared_ptr<sf::Texture> p = std::make_shared<sf::Texture>();
    p.get()->loadFromFile("resources/breakout_pieces.png", sf::IntRect(8, 8, 32, 16));
    game->p1.setTexture(p);
    std::cout << "PlayState::render()" << std::endl;
    game->ball.move(game);
    std::cout<<game->ball.getPosition().y<<std::endl;
    game->ball.draw(game);
    game->p1.draw(game);
    game->window.display();
}