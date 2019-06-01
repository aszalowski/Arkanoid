#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Object.hpp"

class GameEngine;


class Button: public Object{
    public:
        Button(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, bool (* onClickCallback)(GameEngine* game, Button* button) = [](GameEngine* game, Button* button){std::cout << "DEBUG: Using default onClickCallback" << std::endl; return false;});
        Button(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, bool (* onClickCallback)(GameEngine* game, Button* button) = [](GameEngine* game, Button* button){std::cout << "DEBUG: Using default onClickCallback" << std::endl; return false;});

        virtual void draw(GameEngine*) const;

        virtual void setPosition(sf::Vector2f position) { normal.setPosition(position); hovered.setPosition(position); deactivated.setPosition(position);}
        virtual const sf::Vector2f& getPosition() const { return currentSprite->getPosition(); }

        sf::FloatRect getGlobalBounds() const { return currentSprite->getGlobalBounds(); } 

        void hover(){ currentSprite = &hovered;}
        void reset(){ currentSprite = &normal; active=true;}
        void deactivate(){ currentSprite = &deactivated; active=false;}

        bool click(GameEngine* game);
        bool isHovered(const sf::Vector2f& mousePosition);
        bool isActive(){ return active; };


    protected:
        sf::Sprite normal;
        sf::Sprite hovered;
        sf::Sprite deactivated;

        sf::Sprite* currentSprite;

        bool (* onClickCallback)(GameEngine* game, Button* button);
        
        bool active;

        const static sf::Color GREY;

};

class TextButton: public Button{
    public:
        TextButton(sf::Texture* normal, sf::Texture* hovered, const sf::Vector2f& position, const sf::Text& label, bool (* onClickCallback)(GameEngine* game, Button* button) = [](GameEngine* game, Button* button){std::cout << "DEBUG: Using default onClickCallback" << std::endl; return false;});
        TextButton(sf::Texture* normal, const sf::Color& hoveredColor, const sf::Vector2f& position, const sf::Text& label, bool (* onClickCallback)(GameEngine* game, Button* button) = [](GameEngine* game, Button* button){std::cout << "DEBUG: Using default onClickCallback" << std::endl; return false;});

        void reset(){ currentSprite = &normal; label.setFillColor(sf::Color::White); active=true;}
        void deactivate(){ currentSprite = &deactivated; label.setFillColor(Button::GREY); active=false;}

        void draw(GameEngine *) const;
        void setPosition(const sf::Vector2f &);


    private:
        sf::Text label;

};


#endif // __BUTTON_HPP__
