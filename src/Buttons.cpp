#include "../include/Buttons.hpp"

#include "../include/GameEngine.hpp"

#include <iostream> // TODO delete when done debuging

Button::Button(sf::Texture *normal, sf::Texture* clicked, const sf::Vector2f& position)
: normal(*normal), clicked(*clicked), currentSprite(&this->normal)
{
    this->normal.setPosition(position);
    this->clicked.setPosition(position);
}

void Button::draw(GameEngine* game) const
{
    game->window.draw(*currentSprite);
}

TextButton::TextButton(sf::Texture* normal, sf::Texture* clicked, const sf::Vector2f& position, const sf::Text& label)
: Button(normal, clicked, position), label(label)
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