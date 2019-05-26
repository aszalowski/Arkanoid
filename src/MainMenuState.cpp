#include <iostream>
#include <memory>
#include <algorithm>

#include "../include/MainMenuState.hpp"
#include "../include/PlayState.hpp"

#include "../include/Buttons.hpp"

void MainMenuState::init(GameEngine *game)
{
    std::cout << "MainMenuState::init()" << std::endl;
    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("Button 1", *font, mediumFontSize));
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 50));
    buttons.push_back(newButton);

}

void MainMenuState::cleanup(GameEngine *game)
{
    
}

void MainMenuState::pause()
{
}

void MainMenuState::resume()
{
}

void MainMenuState::handleEvents(GameEngine *game, sf::Event event)
{

    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            for(auto button : buttons){
                if(button.get()->isHovered(sf::Vector2f(sf::Mouse::getPosition(game->window)) * game->getScreenRatio())){
                    button.get()->click(game);
                }
            }
        }
    }
    else if(event.type == sf::Event::MouseMoved){
        for(auto button : buttons){
            if(button.get()->isHovered(sf::Vector2f(sf::Mouse::getPosition(game->window)) * game->getScreenRatio())){
                button.get()->hover();
            }
            else
            {
                button.get()->reset();
            }
            
        }
    }

}

void MainMenuState::update(GameEngine *game)
{
}

void MainMenuState::render(GameEngine *game)
{
    for(auto button : buttons)
        button.get()->draw(game);


    game->window.display();
}
