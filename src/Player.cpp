#include "../include/Player.hpp"
#include "../include/GameEngine.hpp"


void Player::setTexture(const std::shared_ptr<sf::Texture> newTexture)
{
    sprite.setTexture(*newTexture.get(), true);
}
void Player::setTexture(std::string path, sf::IntRect rect)
{
    sf::Texture t;
    t.loadFromFile(path, rect);
    sprite.setTexture(t);
}

const sf::Vector2f Player::getPosition() const
{
    return this->sprite.getPosition();
}

void Player::setPosition(const sf::Vector2f &newPosition)
{
    this->sprite.setPosition(newPosition);
}

void Player::setControls(sf::Keyboard::Key left, sf::Keyboard::Key right, sf::Keyboard::Key start)
{
    this->controls.left = left;
    this->controls.right = right;
    this->controls.start = start;
}

void Player::draw(GameEngine *game) const
{
    game->window.draw(this->sprite);
}

void Player::move(int side, GameEngine *game){
    const int step = 5;
    if (getPosition().x > 0 && side < 0)
        sprite.move(side * step, 0);
    if (getPosition().x < game->getVirtualSize().x - sprite.getTextureRect().width && side > 0)
        sprite.move(side * step, 0);
}