#include "../include/GameEngine.hpp"
#include "../include/GameState.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

GameEngine::GameEngine(int width, int height, std::string title, std::string iconPath, int frameLimit, bool vsync) : 
p1(1, sf::Vector2f(304, 324), sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::Space), 
p2(2, sf::Vector2f(304, 20), sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Slash)
{
    std::cout << "GameEngine constructor" << std::endl;
    // Create and setup the main window
    this->window.create(sf::VideoMode(width, height), title); //TODO move to init list
    this->window.setFramerateLimit(frameLimit);
    this->window.setVerticalSyncEnabled(vsync);

    // Set the icon
    sf::Image icon;
    if(icon.loadFromFile(iconPath)) {
        this->window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    }
    else{
        // Fallback to default icon
    }

    //
    textureMenager.addDir("resources/");

    m_running = true;

    
}


void GameEngine::changeState(GameState* state){
    
    // Cleanup the current state
    if( !states.empty() ){
        states.back()->cleanup();
        states.pop_back();
    }
    // Push and initialize new state
    states.push_back(state);
    states.back()->init();

}

void GameEngine::pushState(GameState* state){

    // Pause the current state
    if( !states.empty() )
        states.back()->pause();

    // Push and initialize new state 
    states.push_back(state);
    states.back()->init();

}

void GameEngine::popState(){

    // Cleanup current state
    if( !states.empty() ){
        states.back()->cleanup();
        states.pop_back();
    }

    // Resume previous state
    if( !states.empty() ){
        states.back()->resume();
    }
}

void GameEngine::handleEvents(){
    std::cout<<"handleEvents"<<std::endl;
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            quit();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            quit();
        }
    }
    // Delegate handling events to the current state
    states.back()->handleEvents(this);
}

void GameEngine::update(){

    // Delegate updating screen to the current state
    states.back()->update(this);

}

void GameEngine::render(){

    //Delegate rendering to the current state
    states.back()->render(this);
}
