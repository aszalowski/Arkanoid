#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(){
    std::cout << "PlayState::init()" << std::endl;

  

}

void PlayState::cleanup(GameEngine *game){

}

void PlayState::pause(){

}

void PlayState::resume()
{
}

void PlayState::handleEvents(GameEngine* game){
    
}

void PlayState::update(GameEngine* game){

}

void PlayState::render(GameEngine* game){
    game->window.clear();
    std::cout << "PlayState::render()" << std::endl;
    std::shared_ptr<sf::Texture> t = std::make_shared<sf::Texture>();
    t.get()->loadFromFile("resources/ball.png", sf::IntRect(0, 0, 20, 20));

    game->ball.setTexture(t);
    game->ball.setPosition(sf::Vector2f(100,100));
    game->ball.setSpeed(sf::Vector2f(0.1,0));
    game->ball.move(game);
    std::cout<<game->ball.getPosition().x<<std::endl;
    game->ball.draw(game);
    game->window.display();

}