//
// Created by isaer141 on 12/11/23.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H


#include "../Character/Character.h"

class Enemy : public Character
{
public:
    Enemy(int health);
    void update(const sf::Time& delta) override;
    virtual float getRandomX(const sf::Vector2u& windowSize) const;
    virtual sf::FloatRect getSmallerBounds() const;
};


#endif //TDP005_ENEMY_H
