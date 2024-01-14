
#ifndef TDP005_BACKGROUND_H
#define TDP005_BACKGROUND_H
#include <SFML/Graphics.hpp>
class Background
{
public:
    Background(const sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture backgroundTexture;
    sf::Texture texture;
    sf::Sprite sprite;
};
#endif // BACKGROUND_H