#include "../include/Buttons.hpp"

#include "../include/GameEngine.hpp"

#include <iostream> // TODO delete when done debuging


const sf::Color Button::GREY = sf::Color(100, 100, 100, 255);

Button::Button(sf::Texture *normal, sf::Texture* hovered, const sf::Vector2f& position, bool (* onClickCallback)(GameEngine* game, Button* button))
: normal(*normal), hovered(*hovered), deactivated(*normal), currentSprite(&this->normal), onClickCallback(onClickCallback), active(true)
{
    this->normal.setPosition(position);
    this->hovered.setPosition(position);
    this->deactivated.setPosition(position);
    this->deactivated.setColor(GREY);
}

Button::Button(sf::Texture *normal, const sf::Color& hoveredColor, const sf::Vector2f& position, bool (* onClickCallback)(GameEngine* game, Button* button))
: normal(*normal), hovered(*normal), deactivated(*normal), currentSprite(&this->normal), onClickCallback(onClickCallback), active(true)
{
    this->normal.setPosition(position);
    this->hovered.setPosition(position);
    this->hovered.setColor(hoveredColor);
    this->deactivated.setPosition(position);
    this->deactivated.setColor(sf::Color(GREY));
}

void Button::draw(GameEngine* game) const
{
    game->window.draw(*currentSprite);
}

bool Button::click(GameEngine* game){
    if(active)
        return onClickCallback(game, this);
    return false;
}

bool Button::isHovered(const sf::Vector2f& mousePosition){
    return currentSprite->getGlobalBounds().contains(mousePosition);
}

TextButton::TextButton(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, const sf::Text& label, bool (* onClickCallback)(GameEngine* game, Button* button))
: Button(normal, hovered, position, onClickCallback), label(label)
{
    // Set Origin of the label to it's middle
    sf::FloatRect labelRect = label.getLocalBounds();
    this->label.setOrigin(labelRect.left + labelRect.width/2.0, labelRect.top + labelRect.height/2.0);
    // Position in the middle of the sprite
    this->label.setPosition(currentSprite->getPosition().x + currentSprite->getGlobalBounds().width/2.0, currentSprite->getPosition().y + currentSprite->getGlobalBounds().height/2.0);
}

TextButton::TextButton(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, const sf::Text& label, bool (* onClickCallback)(GameEngine* game, Button* button))
: Button(normal, hoveredColor, position, onClickCallback), label(label)
{
    // Set Origin of the label to it's middle
    sf::FloatRect labelRect = label.getLocalBounds();
    this->label.setOrigin(labelRect.left + labelRect.width/2.0, labelRect.top + labelRect.height/2.0);
    // Position in the middle of the sprite
    this->label.setPosition(currentSprite->getPosition().x + currentSprite->getGlobalBounds().width/2.0, currentSprite->getPosition().y + currentSprite->getGlobalBounds().height/2.0);
}

void TextButton::draw(GameEngine* game) const
{
    game->window.draw(*currentSprite);
    game->window.draw(label);
}

void TextButton::setPosition(const sf::Vector2f& position)
{
    Button::setPosition(position);
    // Position in the middle of the sprite
    this->label.setPosition(currentSprite->getPosition().x + currentSprite->getGlobalBounds().width/2.0, currentSprite->getPosition().y + currentSprite->getGlobalBounds().height/2.0);
}