//
// Created by isaer141 on 2023-12-13.
//

#include <iostream>
#include <SFML/Window/Event.hpp>
#include "MenuState.h"
#include "../Game/Game.h"

MenuState::MenuState(sf::RenderWindow& window) : State(window) {}

void MenuState::run()
{
    // Load font
    if (!font.loadFromFile("../fonts/RubikBubbles-Regular.ttf"))
    {
        std::cerr << "Error loading files" << std::endl;
    }

    //Set position of the fonts
    startText.setFont(font);
    startText.setCharacterSize(40);
    startText.setFillColor(sf::Color::White);
    startText.setString("Press ENTER to start game!");
    // Calculate the position to center the text

    sf::FloatRect textRect = startText.getLocalBounds();
    startText.setOrigin(textRect.left + textRect.width/2.0f,
                        textRect.top  + textRect.height/2.0f);
    startText.setPosition(sf::Vector2f(window.getSize().x/2.0f, window.getSize().y/2.0f));

    bool enterPressed = false;

    while (window.isOpen() && !enterPressed)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter)
            {
                enterPressed = true;
            }
        }

        window.clear();
        window.draw(startText);
        window.display();
    }

    Game game(window);
    game.run();
}