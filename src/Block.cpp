#include "../include/Block.hpp"
#include "../include/GameEngine.hpp"

Block::Block(const int hp, const std::shared_ptr<sf::Texture> texture, const sf::Vector2f position)
{
    this->hp = hp;
    sprite.setTexture(*texture.get(), true);
    sprite.setPosition(position);
}

void Block::draw(GameEngine *game) const
{
    game->window.draw(sprite);
}

void Block::setTexture(const std::shared_ptr<sf::Texture> newTexture)
{
    this->sprite.setTexture(*newTexture.get(), true);
}

void Block::setTexture(GameEngine *game, std::string name, sf::IntRect rect)
{
    setTexture(game->textureMenager.get(name));
    sprite.setTextureRect(rect);
}
