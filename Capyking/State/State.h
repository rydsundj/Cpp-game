//
// Created by isaer141 on 2023-12-13.
//

#ifndef TDP005_STATE_H
#define TDP005_STATE_H

#include <SFML/Graphics/RenderWindow.hpp>

class State
{
public:
    State(sf::RenderWindow& window);
    virtual void run() = 0;

protected:
    sf::RenderWindow& window;
};

#endif //TDP005_STATE_H
