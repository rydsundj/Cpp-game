//
// Created by rydsundj on 2023-12-01.
//

#include <iostream>
#include "Bullet.h"
#include "../Enemy/Enemy.h"

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

void Bullet::handleCollision(std::vector<Object*>& objects, Score& score)
{
    // Collision with enemies
    for (Object* object : objects)
    {
        if (object != this)
        {
            Enemy* enemy = dynamic_cast<Enemy*>(object);
            if (enemy != nullptr)
            {
                // Bullet collision
                if (getBounds().intersects(enemy->getBounds()))
                {
                    this->markForDeletion();
                    enemy->takeDamage();
                    if (enemy->getHealth() <= 0)
                    {
                        enemy->markForDeletion();
                        score.increaseScore(1);
                    }
                }
            }
        }
    }

    // Collision with top wall
    if (this->getBounds().top <= -this->getBounds().height)
    {
        this->markForDeletion();
    }
}