//
// Created by isaer141 on 12/11/23.
//

#ifndef TDP005_ENEMY_H
#define TDP005_ENEMY_H


#include "../Character/Character.h"

class Enemy : public Character
{
public:
    Enemy(const sf::Vector2u& windowSize, int health, sf::Sprite& farmersLand);
    void update(const sf::Time& delta) override;
    sf::FloatRect getBounds() const override;
    float getRandomX(const sf::Vector2u& windowSize) const;
    void handleCollision(std::vector<Object*>& objects, Score& score) override;

private:
    const sf::Sprite farmersLand;
};


#endif //TDP005_ENEMY_H
