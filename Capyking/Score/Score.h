//
// Created by rydsundj on 2023-12-01.
//

#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Score
{
private:
    int currentScore;
    int livesLeft = 3;
    sf::Font font;
    sf::Text scoreText;
    sf::Text livesText;

public:
    Score();
    void increaseScore(int points);
    int getScore() const;
    void updateScoreVisual(sf::RenderWindow& window);
    void removeLives(int currentLives);
    void updateLivesVisual(sf::RenderWindow& window);

};

#endif //TDP005_SCORE_H
