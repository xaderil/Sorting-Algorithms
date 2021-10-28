#define resolutionWidth 1280
#define resolutionHeight 720
#define framerateLimit 90

#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(resolutionWidth, resolutionHeight), "SortingAlgorithms");
    window.setFramerateLimit(framerateLimit);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}

