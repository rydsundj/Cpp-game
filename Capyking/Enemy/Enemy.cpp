//
// Created by isaer141 on 12/11/23.
//
#include <random>
#include "Enemy.h"

Enemy::Enemy(int const health) : Character(health) {}

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

sf::FloatRect Enemy::getSmallerBounds() const
{
    sf::FloatRect smallerBounds = this->getBounds();
    smallerBounds.width -= 100;
    smallerBounds.height -= 80;
    smallerBounds.left += 50;
    smallerBounds.top += 50;
    return smallerBounds;
}