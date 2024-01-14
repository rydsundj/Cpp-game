#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "../Background/Background.h"
#include "../Player/Player.h"
#include "../Background/Background.h"
#include "../Character/Character.h"
#include "../Bullet/Bullet.h"
#include "../Score/Score.h"
#include "../State/State.h"

class Game : public State
{
public:
    Game(sf::RenderWindow& window);
    void run() override;
    void spawnBullet(Player* player);
    void spawnEnemy();
protected:
    std::vector<Object*> objects;
private:
    Background background;
    void processEvents();
    void update(sf::Time deltaTime);
    void render();
    int spawnType;
    sf::Clock spawnClock;
    sf::Clock shootClock;
    const float spawnCapybara = 3.0f;
    const float timeBetweenShots = 0.5f;
    sf::Sprite farmersLand;
    bool spacePressed;
    Score score;
};

#endif // GAME_H
