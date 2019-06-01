#include "../include/GameEngine.hpp"
#include "../include/GameState.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>

GameEngine::GameEngine(int virtualWidth, int virtualHeight, int width, int height, std::string title, std::string iconPath, int frameLimit, bool vsync) : 
p1(1, sf::Keyboard::A, sf::Keyboard::D, sf::Keyboard::Space), 
p2(2, sf::Keyboard::Left, sf::Keyboard::Right, sf::Keyboard::Slash)
{
    std::cout << "GameEngine constructor" << std::endl;
    // Create and setup the main window
    this->window.create(sf::VideoMode(virtualWidth, virtualHeight), title); //TODO move to init list
    this->window.setFramerateLimit(frameLimit);
    this->window.setVerticalSyncEnabled(vsync);
    this->virtualSize = sf::Vector2u(virtualWidth, virtualHeight);

    this->window.setSize(sf::Vector2u(width, height));
    this->screenRatio = (float) virtualWidth / width;

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
    fontMenager.addDir("resources/");

    m_running = true;

    
}


void GameEngine::changeState(GameState* state){
    
    // Cleanup the current state
    if( !states.empty() ){
        states.back()->cleanup(this);
        states.pop_back();
    }
    // Push and initialize new state
    states.push_back(state);
    states.back()->init(this);

}

void GameEngine::pushState(GameState* state){

    // Pause the current state
    if( !states.empty() )
        states.back()->pause();

    // Push and initialize new state 
    states.push_back(state);
    states.back()->init(this);

}

void GameEngine::popState(){

    // Cleanup current state
    if( !states.empty() ){
        states.back()->cleanup(this);
        states.pop_back();
    }

    // Resume previous state
    if( !states.empty() ){
        states.back()->resume();
    }
}

void GameEngine::handleEvents(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            quit();
        }
        else if (event.type == sf::Event::Resized)
        {
            this->resetClock();
        }
        else 
            states.back()->handleEvents(this, event);
    }
    // Delegate handling events to the current state
}

void GameEngine::update(){

    // Delegate updating screen to the current state
    states.back()->update(this);

}

void GameEngine::render(){

    window.clear();
    if(states.back()->isTransparent())
        if(states.size() > 1)
            states.end()[-2]->render(this);
    //Delegate rendering to the current state
    states.back()->render(this);
    window.display();
}
