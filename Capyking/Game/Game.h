#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include "../Background/Background.h"
#include "../Player/Player.h"
#include "../Background/Background.h"
#include "../Capybara/Capybara.h"
#include "../Character/Character.h"
#include "../Bullet/Bullet.h"
#include "../Score/Score.h"
#include "../CapyBoss/CapyBoss.h"
#include "../State/State.h"

class Game : public State
{
public:
    Game(sf::RenderWindow& window);
    void run() override;
    void spawnBullet(Player* player);
    void spawnEnemy();
    void handleBulletCollisions(Bullet* bullet);
    void handleCapybaraCollisions(Capybara* capybara);
    void handleCapyBossCollisions(CapyBoss* capyBoss);
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
    const float spawnCapybara = 0.5f;
    const float timeBetweenShots = 0.1f;
    sf::Sprite farmersLand;
    bool spacePressed;
    bool playerDead;
    Score score;
};

#endif // GAME_H
