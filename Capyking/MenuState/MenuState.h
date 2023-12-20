//
// Created by isaer141 on 2023-12-13.
//

#ifndef TDP005_MENUSTATE_H
#define TDP005_MENUSTATE_H

#include <SFML/Graphics/Text.hpp>
#include "../State/State.h"

class MenuState : public State
{
public:
    MenuState(sf::RenderWindow& window);
    void run() override;
private:
    sf::Font font;
    sf::Text startText;
};

#endif //TDP005_MENUSTATE_H
