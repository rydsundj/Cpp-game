//
// Created by rydsundj on 2023-12-01.
//

#include "Object.h"

Object::Object() : speed(500.0f), markedForDeletion{false} {}

void Object::moveObject(float const deltaX, float const deltaY)
{
    sprite.move(deltaX, deltaY);
}

sf::FloatRect Object::getBounds() const
{
    return sprite.getGlobalBounds();
}

void Object::draw(sf::RenderWindow& window) const
{
    window.draw(sprite);
}

void Object::markForDeletion()
{
    markedForDeletion = true;
}

bool Object::isMarkedForDeletion()
{
    return markedForDeletion;
}