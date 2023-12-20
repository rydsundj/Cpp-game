//
// Created by rydsundj on 2023-12-01.
//

#include "Character.h"

Character::Character(int const health) : Object(), health(health) {}

int Character::getHealth() const
{
    return health;
}

void Character::takeDamage()
{
    health -= 1;
}