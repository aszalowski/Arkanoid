#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(GameEngine *game){
    std::cout << "PlayState::init()" << std::endl;

    game->ball.setPosition(sf::Vector2f(100,100));
    game->ball.setSpeed(sf::Vector2f(0.2, -0.2));

}

void PlayState::cleanup(GameEngine *game){

}

void PlayState::pause(){

}

void PlayState::resume()
{
}

void PlayState::handleEvents(GameEngine* game, sf::Event event){
}

void PlayState::update(GameEngine* game){

}

void PlayState::render(GameEngine* game){
    game->window.clear();
    std::shared_ptr<sf::Texture> t = std::make_shared<sf::Texture>();
    t.get()->loadFromFile("resources/ball.png", sf::IntRect(0, 0, 20, 20));
    game->ball.setTexture(t);
    std::cout << "PlayState::render()" << std::endl;
    game->ball.move(game);
    std::cout<<game->ball.getPosition().y<<std::endl;
    game->ball.draw(game);
    game->window.display();
}