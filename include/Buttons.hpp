#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.hpp"

class GameEngine;


class Button: public Object{
    public:
        Button(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, void (* onClickCallback)(GameEngine* game) = [](GameEngine* game){std::cout << "DEBUG: Using default onClickCallback" << std::endl;});
        Button(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, void (* onClickCallback)(GameEngine* game) = [](GameEngine* game){std::cout << "DEBUG: Using default onClickCallback" << std::endl;});

        virtual void draw(GameEngine*) const;

        virtual void setPosition(sf::Vector2f position) { normal.setPosition(position); hovered.setPosition(position); }
        virtual const sf::Vector2f& getPosition() const { return currentSprite->getPosition(); }

        sf::FloatRect getGlobalBounds() const { return currentSprite->getGlobalBounds(); } 

        void hover(){ currentSprite = &hovered; }
        void reset(){ currentSprite = &normal; }

        void click(GameEngine* game);
        bool isHovered(const sf::Vector2f& mousePosition);


    protected:
        sf::Sprite normal;
        sf::Sprite hovered;

        sf::Sprite* currentSprite;

        void (* onClickCallback)(GameEngine* game);

};

class TextButton: public Button{
    public:
        TextButton(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, const sf::Text& label, void (* onClickCallback)(GameEngine* game) = [](GameEngine* game){std::cout << "DEBUG: Using default onClickCallback" << std::endl;});
        TextButton(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, const sf::Text& label, void (* onClickCallback)(GameEngine* game) = [](GameEngine* game){std::cout << "DEBUG: Using default onClickCallback" << std::endl;});

        void draw(GameEngine *) const;
        void setPosition(const sf::Vector2f &);


    private:
        sf::Text label;
};


#endif // __BUTTON_HPP__
