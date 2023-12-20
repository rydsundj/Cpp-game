//
// Created by isaer141 on 2023-12-13.
//

#ifndef TDP005_ENDSTATE_H
#define TDP005_ENDSTATE_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "../State/State.h"
#include "../Score/Score.h"

class EndState : public State
{
public:
    EndState(sf::RenderWindow& w, Score& score);
    void run() override;
private:
    sf::Font font;
    sf::Text endText;
    Score& score;
};


#endif //TDP005_ENDSTATE_H
