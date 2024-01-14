#include "Background.h"
#include <iostream>

Background::Background(const sf::RenderWindow& window)
{

    if (!backgroundTexture.loadFromFile("../images/background.png"))
    {
        std::cerr << "Failed to load background image" << std::endl;
    }


    sprite.setTexture(backgroundTexture);
    sf::Vector2u windowSize = window.getSize();
    sf::Vector2u textureSize = backgroundTexture.getSize();
    float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    float scaleY = static_cast<float>(windowSize.y) / textureSize.y;
    sprite.setScale(scaleX, scaleY);


}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
