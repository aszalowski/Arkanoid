#include "../include/MainMenuState.hpp"
#include "../include/HotSeatMenuState.hpp"
#include "../include/HotSeatPlayState.hpp"


void HotSeatMenuState::init(GameEngine* game)
{
    std::cout << "HotSeatMenuState::init()" << std::endl;
    font = game->fontMenager.get("pixel.ttf").get();
    const_cast<sf::Texture&>(font->getTexture(mediumFontSize)).setSmooth(false);

    const uint GAP = 15;

    P1skinChooser.init(game->textureMenager.get("paddle_skins.png").get(), sf::IntRect(0, 0, 32, 16), sf::Vector2f(0, 0));
    P1skinChooser.getSprite()->scale(sf::Vector2f(3, 3));
    P1skinChooser.setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - P1skinChooser.getGlobalBounds().width/2.0, 80));

    P2skinChooser.init(game->textureMenager.get("paddle_skins.png").get(), sf::IntRect(0, 0, 32, 16), sf::Vector2f(0, 0));
    P2skinChooser.getSprite()->scale(sf::Vector2f(3, 3));
    P2skinChooser.setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - P2skinChooser.getGlobalBounds().width/2.0, 160));

    ballChooser.init(game->textureMenager.get("ball_skins.png").get(), sf::IntRect(0, 0, 8, 8), sf::Vector2f(0, 0), 1);
    ballChooser.getSprite()->scale(sf::Vector2f(3, 3));
    ballChooser.setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - ballChooser.getGlobalBounds().width/2.0, 250));

    std::shared_ptr<TextButton> newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PLAY", *font, mediumFontSize), [](GameEngine* game, Button* button){game->changeState(HotSeatPlayState::instance()); return true;});
    newButton.get()->setPosition(sf::Vector2f(game->getVirtualSize().x/2.0 - newButton.get()->getGlobalBounds().width/2.0, 300));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("NEXT", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->P1skinChooser.next(); return false;});
    newButton.get()->setPosition(sf::Vector2f(P1skinChooser.getGlobalBounds().left + P2skinChooser.getGlobalBounds().width + GAP, P1skinChooser.getGlobalBounds().top + P1skinChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PREV", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->P1skinChooser.prev(); return false;});
    newButton.get()->setPosition(sf::Vector2f(P1skinChooser.getGlobalBounds().left - newButton->getGlobalBounds().width - GAP, P1skinChooser.getGlobalBounds().top + P1skinChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("NEXT", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->P2skinChooser.next(); return false;});
    newButton.get()->setPosition(sf::Vector2f(P2skinChooser.getGlobalBounds().left + P2skinChooser.getGlobalBounds().width + GAP, P2skinChooser.getGlobalBounds().top + P2skinChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PREV", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->P2skinChooser.prev(); return false;});
    newButton.get()->setPosition(sf::Vector2f(P2skinChooser.getGlobalBounds().left - newButton->getGlobalBounds().width - GAP, P2skinChooser.getGlobalBounds().top + P2skinChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);


    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("NEXT", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->ballChooser.next(); return false;});
    newButton.get()->setPosition(sf::Vector2f(ballChooser.getGlobalBounds().left + ballChooser.getGlobalBounds().width + GAP, ballChooser.getGlobalBounds().top + ballChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);

    newButton = std::make_shared<TextButton>(game->textureMenager.get("button.png").get(), sf::Color(200, 200, 200, 200), sf::Vector2f(0, 0), sf::Text("PREV", *font, mediumFontSize), [](GameEngine* game, Button* button){HotSeatMenuState::instance()->ballChooser.prev(); return false;});
    newButton.get()->setPosition(sf::Vector2f(ballChooser.getGlobalBounds().left - newButton->getGlobalBounds().width - GAP, ballChooser.getGlobalBounds().top + ballChooser.getGlobalBounds().height / 2.0 - newButton->getGlobalBounds().height / 2.0));
    buttons.push_back(newButton);


    objects.push_back(P1skinChooser.getSprite());
    objects.push_back(P2skinChooser.getSprite());
    objects.push_back(ballChooser.getSprite());

}

void HotSeatMenuState::cleanup(GameEngine* game)
{
    game->p1.setTexture(game->textureMenager.get("paddle_skins.png"));
    game->p1.modifySprite().setTextureRect(P1skinChooser.getTextureRect());

    game->p2.setTexture(game->textureMenager.get("paddle_skins.png"));
    game->p2.modifySprite().setTextureRect(P2skinChooser.getTextureRect());

    game->ball.setTexture(game->textureMenager.get("ball_skins.png"));
    game->ball.modifySprite().setTextureRect(ballChooser.getTextureRect());


}
