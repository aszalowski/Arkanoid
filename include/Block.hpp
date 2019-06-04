#ifndef __BLOCK_HPP__
#define __BLOCK_HPP__

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <memory>

#include "Object.hpp"
#include "Collision.hpp"

class GameEngine;
///Class of block - destroyable object in the PlayState
class Block : public Object
{
private:
    uint hp; ///< Health points - how meny hits it take to destroy
    sf::Sprite sprite; ///< Drawable representation of a texture, with its own transformations, color, etc.

public:
    Block(); 
    Block(const int, const std::shared_ptr<sf::Texture>, const sf::Vector2f); ///< Constructor with health points, texture shared pointer from ResourceManager, Vector of position

    void draw(GameEngine *) const;
    const uint getHp() const { return hp; }
    const sf::Vector2f getPosition() const { return sprite.getPosition(); }
    void setPosition(const sf::Vector2f &newPosition) { sprite.setPosition(newPosition); }
    const sf::Sprite &getSprite() const { return sprite; }
    sf::Sprite &modifySprite() { return sprite; }
    void setTexture(const std::shared_ptr<sf::Texture>); ///< Setting texture with a shared pointer from ResourceManager
    void setTexture(GameEngine *, std::string, sf::IntRect); 
    Block operator--();
    ~Block() {} 
};

#endif // __BLOCK_HPP__
