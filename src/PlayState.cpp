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
    
    int v_width = 640;
    int v_height = 360;
    std::cout << "PlayState::render()" << std::endl;
    sf::Texture t;
    t.loadFromFile("resources/breakout_pieces.png", sf::IntRect(8,8,32,16));
    sf::Sprite s;
    s.setTexture(t);
    s.setPosition(355, 200);
    game->window.draw(s);
    game->window.display();

}