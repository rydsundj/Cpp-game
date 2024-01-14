//
// Created by isaer141 on 12/11/23.
//
#include <random>
#include <iostream>
#include "Enemy.h"
#include "../Player/Player.h"

Enemy::Enemy(const sf::Vector2u& windowSize, int const health, sf::Sprite& farmersLand) : Character(health), farmersLand(farmersLand)
{
    if (health == 1)
    {
        speed = 150.0f;
        if (!texture.loadFromFile("../images/capybara.png"))
        {
            std::cerr << "Failed to load image" << std::endl;
        }
        sprite.setTexture(texture);
        this->sprite.setScale(0.15f, 0.15f);
    }
    else if (health == 5)
    {
        speed = 75.0f;
        if (!texture.loadFromFile("../images/capyboss.png"))
        {
            std::cerr << "Failed to load image" << std::endl;
        }
        sprite.setTexture(texture);
        this->sprite.setScale(0.25f, 0.25f);
    }
    this->sprite.setPosition(getRandomX(windowSize), -sprite.getGlobalBounds().height - 500);
}

void Enemy::update(const sf::Time &delta)
{
    moveObject(0, speed * delta.asSeconds());
}

float Enemy::getRandomX(const sf::Vector2u& windowSize) const
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distr(0.0f, windowSize.x - sprite.getGlobalBounds().width);
    float randomX = distr(gen);
    return randomX;
}

sf::FloatRect Enemy::getBounds() const
{
    sf::FloatRect smallerBounds = sprite.getGlobalBounds();
    smallerBounds.width -= 100;
    smallerBounds.height -= 80;
    smallerBounds.left += 50;
    smallerBounds.top += 50;
    return smallerBounds;
}

void Enemy::handleCollision(std::vector<Object*>& objects, Score& score)
{
    // Check collision between capybara and farmersLand, which is always at 3/4 of the map height
    if (this->getBounds().intersects(farmersLand.getGlobalBounds()))
    {
        this->markForDeletion();
        for (Object* object : objects)
        {
            if (object != this)
            {
                Player* player = dynamic_cast<Player*>(object);
                if (player != nullptr)
                {
                    player->takeDamage();
                    score.removeLives(player->getHealth());
                    break;
                }
            }
        }
    }
}