#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <SFML/Graphics.hpp>

#include "Object.hpp"


class Button: public Object{
    public:
        Button(sf::Texture* normal, sf::Texture* clicked, const sf::Vector2f& position);

        virtual void draw(GameEngine*) const;

        virtual void setPosition(const sf::Vector2f & position) { normal.setPosition(position); clicked.setPosition(position); }
        virtual const sf::Vector2f& getPosition() const { return currentSprite->getPosition(); }


    protected:
        sf::Sprite normal;
        sf::Sprite clicked;

        sf::Sprite* currentSprite;
};

class TextButton: public Button{
    public:
        TextButton(sf::Texture* normal, sf::Texture* clicked, const sf::Vector2f& position, const sf::Text& label);

        void draw(GameEngine *) const;
        void setPosition(const sf::Vector2f &);


    private:
        sf::Text label;
};


#endif // __BUTTON_HPP__
