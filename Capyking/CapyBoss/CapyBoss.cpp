//
// Created by rydsundj on 2023-12-01.
//

#include <random>
#include "CapyBoss.h"
#include <iostream>

CapyBoss::CapyBoss(const sf::Vector2u& windowSize) : Enemy(5)
{
    speed = 75.0f;

    if (!texture.loadFromFile("../images/capyboss.png"))
    {
        std::cerr << "Failed to load image" << std::endl;
    }
    sprite.setTexture(texture);
    this->sprite.setScale(0.25f, 0.25f);
    this->sprite.setPosition(getRandomX(windowSize), -sprite.getGlobalBounds().height - 500);
}
