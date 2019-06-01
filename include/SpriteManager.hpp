#ifndef __SPRITEMANAGER_HPP__
#define __SPRITEMANAGER_HPP__

#include <SFML/Graphics.hpp>

class SpriteManager
{
    public:
        void init(sf::Texture* texture, const sf::IntRect& initialRect, const sf::Vector2f& position, int gap=0);

        inline sf::Sprite* getSprite(){ return &sprite; };
        inline sf::IntRect getTextureRect(){ return sprite.getTextureRect(); }
        inline sf::FloatRect getGlobalBounds(){ return sprite.getGlobalBounds(); }
        inline void setPosition(const sf::Vector2f& position){ sprite.setPosition(position); }


        void next();
        void prev();



    private:
        sf::Sprite sprite;
        int gap; //NOTE: scale not working probably because gap not scaled

};

#endif // __SPRITEMANAGER_HPP__