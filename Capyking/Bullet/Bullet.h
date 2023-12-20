//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_BULLET_H
#define TDP005_BULLET_H

#include "../Object/Object.h"
#include "../Player/Player.h"

class Bullet : public Object
{
public:
    Bullet(Player* player);
    void update(const sf::Time& delta) override;
};

#endif //TDP005_BULLET_H
