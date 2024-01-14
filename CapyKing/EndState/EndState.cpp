//
// Created by isaer141 on 2023-12-13.
//

#include <iostream>
#include "EndState.h"

EndState::EndState(sf::RenderWindow& w, Score& score) : State(w), score(score) {}

void EndState::run()
{
    // Load font
    if (!font.loadFromFile("../fonts/RubikBubbles-Regular.ttf"))
    {
        std::cerr << "Error loading files" << std::endl;
    }

    //Set position of the fonts
    endText.setFont(font);
    endText.setCharacterSize(40);
    endText.setFillColor(sf::Color::White);
    endText.setString("Score: " + std::to_string(score.getScore()) + "\nPress X to quit");
    sf::FloatRect textRect = endText.getLocalBounds();
    endText.setOrigin(textRect.left + textRect.width/2.0f,
                      textRect.top + textRect.height/2.0f);
    endText.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X))
            {
                window.close();
            }
        }

        window.clear();
        window.draw(endText);
        window.display();
    }
}