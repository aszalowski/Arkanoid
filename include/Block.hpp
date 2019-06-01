#ifndef __BLOCK_HPP__
#define __BLOCK_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"
#include "Collision.hpp"

class GameEngine;

class Block : public Object
{
private:
    int hp;
    sf::Sprite sprite;

public:
    Block();
    Block(const int, const std::shared_ptr<sf::Texture>, const sf::Vector2f);

    void draw(GameEngine *) const;

    const sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void setPosition(const sf::Vector2f &newPosition) { sprite.setPosition(newPosition); }
    const sf::Sprite &getSprite() const{ return sprite; }
    sf::Sprite &modifySprite() { return sprite; }
    void setTexture(const std::shared_ptr<sf::Texture> );
    void setTexture(GameEngine *, std::string, sf::IntRect);

    ~Block() {}
};

#endif // __BLOCK_HPP__
