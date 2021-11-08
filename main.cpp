#include "SortingAlgorithms.h"

const uint32_t resolutionWidth = 1280.f;
const uint32_t resolutionHeight = 720.f;
const uint32_t framerateLimit = 1500;
const float columnNumber = 1000;

int main() {

    sf::RenderWindow window(sf::VideoMode(resolutionWidth, resolutionHeight), "SortingAlgorithms");
    window.setFramerateLimit(framerateLimit);

    Field field(columnNumber, 0, 0, resolutionWidth, resolutionHeight);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        field.randomizeColumns();
        SortingAlgorithms::BubbleSort(field, window, event);
        field.drawAllColumns(window);

        window.display();
    }
    return 0;
}

