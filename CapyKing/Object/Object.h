//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_OBJECT_H
#define TDP005_OBJECT_H
#include <SFML/Graphics.hpp>
#include "../Score/Score.h"


class Object
{
public:
    Object();
    virtual ~Object() = default;
    virtual void moveObject(float const deltaX, float const deltaY);
    virtual void update(const sf::Time& delta) = 0;
    virtual void draw(sf::RenderWindow& window) const;
    virtual sf::FloatRect getBounds() const;
    virtual void handleCollision(std::vector<Object*>& objects, Score& score) = 0;
    virtual void markForDeletion();
    virtual bool isMarkedForDeletion();

protected:
    float speed;
    sf::Sprite sprite;
    sf::Texture texture;
    bool markedForDeletion;
};

#endif //TDP005_OBJECT_H
