#include "../include/EndGameState.hpp"
#include "../include/MainMenuState.hpp"


void EndGameState::init(GameEngine* game)
{

    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);
    title.setFont(*font);
    title.setPosition(100, 100);
    title.setCharacterSize(25);

    if(game->p2.active)
    {
        if(game->p1.getHp() == 0 || game->p1.getScore() < game->p2.getScore()){
            title.setString("Player 2 won!");
        }
        else if(game->p2.getHp() == 0 || game->p2.getScore() < game->p2.getScore())
        {
            title.setString("Player 1 won!");
        }
        else
        {
            title.setString("Err");
        }
    }
    else
    {
        if(game->p1.getHp() == 0)
            title.setString("You Lost!");
        else
            title.setString("You Won!");
        
    }

    game->p2.active = false;


    objects.push_back(&title);
    
    

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("EXIT", *font, mediumFontSize), [](GameEngine* game, Button* button){game->popState(); game->changeState(MainMenuState::instance()); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 300));
    buttons.push_back(newButton);

}