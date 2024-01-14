#include "Score.h"
#include <iostream>
Score::Score() : currentScore(0)
{
    // Load font
    if (!font.loadFromFile("../fonts/RubikBubbles-Regular.ttf"))
    {
        std::cerr << "Error loading files" << std::endl;
    }

    //Set position of the fonts
    scoreText.setFont(font);
    scoreText.setCharacterSize(24);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    livesText.setFont(font);
    livesText.setCharacterSize(24);
    livesText.setFillColor(sf::Color::Black);
    livesText.setPosition(850, 10);
}

// increase score by one
void Score::increaseScore(int points)
{
    currentScore += points;
}

// kanske inte behövs
int Score::getScore() const
{
    return currentScore;
}

//draw the font of score
void Score::updateScoreVisual(sf::RenderWindow& window)
{
    scoreText.setString("Score: " + std::to_string(currentScore));
    scoreText.setPosition(10,10);
    window.draw(scoreText);


}
//set lives left
void Score::removeLives(int currentLives)
{
    livesLeft = currentLives;
}
//draw font of lives left
void Score::updateLivesVisual(sf::RenderWindow& window)
{
    livesText.setString("Lives left: " + std::to_string(livesLeft));
    sf::Vector2u windowSize = window.getSize();
    float livesTextWidth = livesText.getLocalBounds().width;
    livesText.setPosition(windowSize.x - livesTextWidth - 10, 10);
    window.draw(livesText);
}