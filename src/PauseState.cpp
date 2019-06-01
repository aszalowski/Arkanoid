#include "../include/PauseState.hpp"

void PauseState::init(GameEngine* game){

    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PLAY", *font, mediumFontSize), [](GameEngine* game, Button* button){game->popState(); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 300));
    buttons.push_back(newButton);
}