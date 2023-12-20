//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_CAPYBARA_H
#define TDP005_CAPYBARA_H

#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include <SFML/Graphics.hpp>

class Capybara : public Enemy
{
public:
    Capybara(const sf::Vector2u& windowSize);
};

#endif //TDP005_CAPYBARA_H
