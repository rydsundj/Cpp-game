#include "Game.h"
#include "../EndState/EndState.h"
#include <iostream>

Game::Game(sf::RenderWindow& w) : State(w), background(w), farmersLand(), spacePressed(false), spawnType{}, playerDead(false), objects{}
{
    float width = static_cast<float>(window.getSize().x);
    float height = static_cast<float>(window.getSize().y * 3/4);

    sf::IntRect size(0, 0, width, height);
    farmersLand.setTextureRect(size);

    this->farmersLand.setScale(1.0f, 1.0f);
    this->farmersLand.setPosition(0, height);
}

void Game::run()
{
    objects.push_back(new Player(window.getSize()));
    sf::Clock clock;
    while (window.isOpen())
    {
        // Events in game, user inputs etc.
        processEvents();

        // Clock reset for every frame
        sf::Time deltaTime = clock.restart();

        // Spawn enemy if it's time to
        spawnEnemy();

        update(deltaTime);

        if (playerDead)
        {
            break;
        }

        score.updateScoreVisual(window);
        score.updateLivesVisual(window);
        render();
    }

    for (Object* object : objects)
    {
        delete object;
    }

    EndState endState(window, score);
    endState.run();
}

void Game::spawnEnemy() {
    // Check if it's time to spawn an enemy
    if(spawnClock.getElapsedTime().asSeconds() >= spawnCapybara)
    {
        if (spawnType == 4)
        {
            objects.push_back(new CapyBoss{window.getSize()});
            spawnType = 0;
        }
        else
        {
            objects.push_back(new Capybara{window.getSize()});
            ++spawnType;
        }
        spawnClock.restart();
    }
}

void Game::spawnBullet(Player* player)
{
    objects.push_back(new Bullet{player});
}

void Game::processEvents()
{
    sf::Event event;
    Player* player{};
    for (Object* object : objects)
    {
        Player* p = dynamic_cast<Player*>(object);
        if (p != nullptr)
        {
            player = p;
            break;
        }
    }
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed &&
                 event.key.code == sf::Keyboard::LShift &&
                 !this->spacePressed &&
                 shootClock.getElapsedTime().asSeconds() >= timeBetweenShots)
        {
            this->spacePressed = true;
            spawnBullet(player);
            shootClock.restart();
        }
        else if (event.type == sf::Event::KeyReleased &&
                 event.key.code == sf::Keyboard::LShift)
        {
            this->spacePressed = false;
        }
        player->handleInput(event);
    }
}

void Game::handleBulletCollisions(Bullet* bullet)
{
    // Collision with capybaras
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        Object* object = *it;
        Capybara* capybara = dynamic_cast<Capybara*>(object);
        if (capybara != nullptr && bullet->getBounds().intersects(capybara->getSmallerBounds()))
        {
            capybara->takeDamage();
            if (capybara->getHealth() <= 0)
            {
                delete capybara;
                score.increaseScore(1);
                it = objects.erase(it);
            }
            objects.erase(std::remove(objects.begin(), objects.end(), bullet), objects.end());
            delete bullet;
            return;
        }
    }

    // Collision with capybara bosses
    for (auto it = objects.begin(); it != objects.end(); ++it)
    {
        Object* object = *it;
        CapyBoss* capyBoss = dynamic_cast<CapyBoss*>(object);
        if (capyBoss != nullptr && bullet->getBounds().intersects(capyBoss->getSmallerBounds()))
        {
            capyBoss->takeDamage();
            if (capyBoss->getHealth() <= 0)
            {

                delete capyBoss;
                score.increaseScore(1);
                it = objects.erase(it);
            }
            objects.erase(std::remove(objects.begin(), objects.end(), bullet), objects.end());
            delete bullet;
            return;
        }
    }

    // Collision with top wall
    if (bullet->getBounds().top <= -bullet->getBounds().height)
    {
        objects.erase(std::remove(objects.begin(), objects.end(), bullet), objects.end());
        delete bullet;
    }
}

void Game::handleCapybaraCollisions(Capybara* capybara)
{
    if (capybara->getSmallerBounds().intersects(farmersLand.getGlobalBounds()))
    {
        objects.erase(std::remove(objects.begin(), objects.end(), capybara), objects.end());
        delete capybara;
        for (Object* object : objects)
        {
            Player* player = dynamic_cast<Player*>(object);
            if (player != nullptr)
            {
                player->takeDamage();
                score.removeLives(player->getHealth());

                if (player->getHealth() <= 0)
                {
                    playerDead = true;
                }
            }
        }
    }
}

void Game::handleCapyBossCollisions(CapyBoss* capyBoss)
{
    if (capyBoss->getSmallerBounds().intersects(farmersLand.getGlobalBounds()))
    {
        objects.erase(std::remove(objects.begin(), objects.end(), capyBoss), objects.end());
        delete capyBoss;
        for (Object* object : objects)
        {
            Player* player = dynamic_cast<Player*>(object);
            if (player != nullptr)
            {
                player->takeDamage();
                score.removeLives(player->getHealth());

                if (player->getHealth() <= 0)
                {
                    playerDead = true;
                }
            }
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    for (Object* object : objects)
    {
        object->update(deltaTime);

        // Handle collision
        Bullet* bullet = dynamic_cast<Bullet*>(object);
        if (bullet != nullptr)
        {
            handleBulletCollisions(bullet);
        }
        else if (Capybara* capybara = dynamic_cast<Capybara*>(object))
        {
            handleCapybaraCollisions(capybara);
        }
        else if (CapyBoss* capyBoss = dynamic_cast<CapyBoss*>(object))
        {
            handleCapyBossCollisions(capyBoss);
        }
    }
}

void Game::render()
{
    window.clear();
    background.draw(window);
    window.draw(farmersLand);

    for(const auto& object : objects)
    {
        object->draw(window);
    }

    score.updateScoreVisual(window);
    score.updateLivesVisual(window);

    window.display();
}

