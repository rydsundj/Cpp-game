//
// Created by rydsundj on 2023-12-01.
//

#include <iostream>
#include "Bullet.h"

Bullet::Bullet(Player* player) : Object()
{
    if (!texture.loadFromFile("../images/bullet.png"))
    {
        std::cerr << "Failed to load image" << std::endl;
    }
    sprite.setTexture(texture);
    this->sprite.setScale(0.1f, 0.1f);
    sf::Vector2f playerPosition = player->getSprite().getPosition();
    this->sprite.setPosition(playerPosition.x + 78, playerPosition.y + -48);
}

void Bullet::update(const sf::Time& delta)
{
    moveObject(0, -speed * delta.asSeconds());
}