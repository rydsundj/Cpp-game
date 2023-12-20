//
// Created by rydsundj on 2023-12-01.
//
#include "Capybara.h"
#include <iostream>

Capybara::Capybara(const sf::Vector2u& windowSize) : Enemy(1)
{
    speed = 150.0f;

    if (!texture.loadFromFile("../images/capybara.png"))
    {
        std::cerr << "Failed to load image" << std::endl;
    }
    sprite.setTexture(texture);
    this->sprite.setScale(0.15f, 0.15f);
    this->sprite.setPosition(getRandomX(windowSize), -sprite.getGlobalBounds().height - 500);
}
