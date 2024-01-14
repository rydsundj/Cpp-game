
#include "Game/Game.h"
#include "MenuState/MenuState.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

std::pair<int, int> readSizeFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::string line;
    int width = 0, height = 0;

    while (getline(file, line))
    {
        size_t pos = line.find('=');
        if (pos != std::string::npos)
        {
            std::string key = line.substr(0, pos);
            int value = std::stoi(line.substr(pos + 1));

            if (key == "width") {
                width = value;
            } else if (key == "height")
            {
                height = value;
            }
        }
    }
    if (width <= 0 || width > 1920 || height <= 0 || height > 1080)
    {
        // default width, height
        width = 800;
        height = 600;
    }
    return {width, height};
}
int main() 
{
    auto [width, height] = readSizeFromFile("../size.txt");

    sf::RenderWindow window;
    window.create(sf::VideoMode(width, height), "Capyking");
    window.setVerticalSyncEnabled(true);

    MenuState menu(window);
    menu.run();
    return 0;
}
