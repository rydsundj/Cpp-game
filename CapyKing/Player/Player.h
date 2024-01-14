//
// Created by rydsundj on 2023-12-01.
//

#ifndef TDP005_PLAYER_H
#define TDP005_PLAYER_H

#include "../Character/Character.h"
#include <SFML/Graphics.hpp>

class Player : public Character
{
public:
    Player(const sf::Vector2u& windowSize);
    void handleInput(const sf::Event& event);
    sf::Sprite getSprite() const;
    void update(const sf::Time& delta) override;
    void handleCollision(std::vector<Object*>& objects, Score& score) override;
    bool isDead();
private:
    bool leftPressed;
    bool rightPressed;
    const int windowWidth;
};

#endif //TDP005_PLAYER_H
