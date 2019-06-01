#include "../include/Player.hpp"
#include "../include/GameEngine.hpp"


void Player::setTexture(const std::shared_ptr<sf::Texture> newTexture)
{
    sprite.setTexture(*newTexture.get(), true);
}
void Player::setTexture(GameEngine *game, std::string name, sf::IntRect rect)
{
    setTexture(game->textureMenager.get(name));
    sprite.setTextureRect(rect);
}

const sf::Vector2f& Player::getPosition() const
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

void Player::move(int side, sf::Vector2u virtualSize, uint time){
    if (getPosition().x > 0 && side < 0)
        sprite.move(side * moveStep * time, 0);
    if (getPosition().x < virtualSize.x - sprite.getTextureRect().width && side > 0)
        sprite.move(side * moveStep * time, 0);
}

Player Player::operator--(int a)
{
    
    this->hp--;
    return *this;
}