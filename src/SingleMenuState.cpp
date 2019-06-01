#include "../include/MainMenuState.hpp"
#include "../include/SingleMenuState.hpp"
#include "../include/PlayState.hpp"


void SingleMenuState::init(GameEngine* game)
{
    std::cout << "SingleMenuState::init()" << std::endl;
    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PLAY", *font, mediumFontSize), [](GameEngine* game, Button* button){game->changeState(PlayState::instance()); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 300));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("NEXT", *font, mediumFontSize), [](GameEngine* game, Button* button){SingleMenuState::instance()->skinChooser.next(); return false;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 130));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PREV", *font, mediumFontSize), [](GameEngine* game, Button* button){SingleMenuState::instance()->skinChooser.prev(); return false;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 180));
    buttons.push_back(newButton);

    skinChooser.init(game->textureMenager.get("paddle_skins.png").get(), sf::IntRect(0, 0, 32, 16), sf::Vector2f(0, 0));
    skinChooser.getSprite()->scale(sf::Vector2f(3, 3));
    skinChooser.setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - skinChooser.getGlobalBounds().width/2.0, 80));

    objects.push_back(skinChooser.getSprite());

}

void SingleMenuState::cleanup(GameEngine* game)
{
    game->p1.setTexture(game->textureMenager.get("paddle_skins.png"));
    game->p1.modifySprite().setTextureRect(skinChooser.getTextureRect());

}
