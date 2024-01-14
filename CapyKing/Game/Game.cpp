#include "Game.h"
#include "../EndState/EndState.h"
#include "../Enemy/Enemy.h"
#include <iostream>

Game::Game(sf::RenderWindow& w) : State(w), background(w), farmersLand(), spacePressed(false), spawnType{}, objects{}
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
    Player* player = dynamic_cast<Player*>(objects[0]);
    while (window.isOpen())
    {
        // Events in game, user inputs etc.
        processEvents();

        // Clock reset for every frame
        sf::Time deltaTime = clock.restart();

        // Spawn enemy if it's time to
        spawnEnemy();

        update(deltaTime);

        if (player->isDead())
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
            objects.push_back(new Enemy{window.getSize(), 5, farmersLand});
            spawnType = 0;
        }
        else
        {
            objects.push_back(new Enemy{window.getSize(), 1, farmersLand});
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
                 event.key.code == sf::Keyboard::Space &&
                 !this->spacePressed &&
                 shootClock.getElapsedTime().asSeconds() >= timeBetweenShots)
        {
            this->spacePressed = true;
            spawnBullet(player);
            shootClock.restart();
        }
        else if (event.type == sf::Event::KeyReleased &&
                 event.key.code == sf::Keyboard::Space)
        {
            this->spacePressed = false;
        }
        player->handleInput(event);
    }
}

void Game::update(sf::Time deltaTime)
{
    for (Object* object : objects)
    {
        object->update(deltaTime);
        object->handleCollision(objects, score);
    }

    // Delete objects marked for deletion
    for (auto it = objects.begin(); it != objects.end();)
    {
        if ((*it)->isMarkedForDeletion())
        {
            delete *it;
            it = objects.erase(it);
        }
        else
        {
            ++it;
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

