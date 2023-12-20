//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_CHARACTER_H
#define TDP005_CHARACTER_H

#include "../Object/Object.h"

class Character : public Object
{
public:
    Character(int const health);
    virtual void takeDamage();
    virtual int getHealth() const;

protected:
    int health;
};

#endif //TDP005_CHARACTER_H
