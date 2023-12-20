//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_CAPYBOSS_H
#define TDP005_CAPYBOSS_H

#include "../Enemy/Enemy.h"

class CapyBoss : public Enemy
{
public:
    CapyBoss(const sf::Vector2u& windowSize);
};

#endif //TDP005_CAPYBOSS_H
