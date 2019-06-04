#include "../include/SpriteManager.hpp"

#include <iostream> //TODO delete after done debbuging

void SpriteManager::init(sf::Texture* texture, const sf::IntRect& initialRect, const sf::Vector2f& position, int gap)
{
    this->gap = gap;
    sprite.setTexture(*texture);
    sprite.setTextureRect(initialRect);
    sprite.setPosition(position);
    sprite.setScale(sf::Vector2f(1, 1));

}

void SpriteManager::next()
{
    if((unsigned int)(sprite.getTextureRect().left + sprite.getTextureRect().width + gap) < sprite.getTexture()->getSize().x){
        sf::IntRect newRect(sprite.getTextureRect());
        newRect.left += (newRect.width + gap);
        sprite.setTextureRect(newRect);
    }
}

void SpriteManager::prev()
{
    if(sprite.getTextureRect().left  >= + sprite.getTextureRect().width + gap){
        sf::IntRect newRect(sprite.getTextureRect());
        newRect.left -= (newRect.width + gap);
        sprite.setTextureRect(newRect);
    }

}