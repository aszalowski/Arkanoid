#include <iostream>

#include "../include/PlayState.hpp"

void PlayState::init(){
    std::cout << "PlayState::init()" << std::endl;

  

}

void PlayState::cleanup(){

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
    std::cout << "PlayState::render()" << std::endl;
    game->p1.setTexture("resources/breakout_pieces.png", sf::IntRect(8, 8, 32, 16));
    game->ball.setTexture("resources/ball.png", sf::IntRect(0,0,20,20));
    sf::Sprite s;
    //s.setTexture(game->ball.getTexture());
    s.setTexture(*game->ball.sprite.getTexture());
    game->window.draw(s);
    //std::cout<<game->ball.sprite.<<std::endl;
    game->ball.draw(game);
    game->p1.draw(game);
    game->window.display();

}