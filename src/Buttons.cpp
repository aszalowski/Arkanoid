#include "../include/Buttons.hpp"

#include "../include/GameEngine.hpp"

#include <iostream> // TODO delete when done debuging

Button::Button(sf::Texture *normal, sf::Texture* hovered, const sf::Vector2f& position, void (* onClickCallback)(GameEngine* game))
: normal(*normal), hovered(*hovered), currentSprite(&this->normal), onClickCallback(onClickCallback)
{
    this->normal.setPosition(position);
    this->hovered.setPosition(position);
    this->hovered.setColor(sf::Color(200, 200, 200, 100));
}

Button::Button(sf::Texture *normal, const sf::Color& hoveredColor, const sf::Vector2f& position, void (* onClickCallback)(GameEngine* game))
: normal(*normal), hovered(*normal), currentSprite(&this->normal), onClickCallback(onClickCallback)
{
    this->normal.setPosition(position);
    this->hovered.setPosition(position);
    this->hovered.setColor(hoveredColor);
}

void Button::draw(GameEngine* game) const
{
    game->window.draw(*currentSprite);
}

void Button::click(GameEngine* game){
    onClickCallback(game);
}

bool Button::isHovered(const sf::Vector2f& mousePosition){
    return currentSprite->getGlobalBounds().contains(mousePosition);
}

TextButton::TextButton(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, const sf::Text& label, void (* onClickCallback)(GameEngine* game))
: Button(normal, hovered, position, onClickCallback), label(label)
{
    // Set Origin of the label to it's middle
    sf::FloatRect labelRect = label.getLocalBounds();
    this->label.setOrigin(labelRect.left + labelRect.width/2.0, labelRect.top + labelRect.height/2.0);
    // Position in the middle of the sprite
    this->label.setPosition(currentSprite->getPosition().x + currentSprite->getGlobalBounds().width/2.0, currentSprite->getPosition().y + currentSprite->getGlobalBounds().height/2.0);
}

TextButton::TextButton(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, const sf::Text& label, void (* onClickCallback)(GameEngine* game))
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