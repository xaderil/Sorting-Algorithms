#include "SortingAlgorithms.h"

const uint32_t resolutionWidth = 1280.f;
const uint32_t resolutionHeight = 720.f;
const uint32_t framerateLimit = 90;
const float columnNumber = 100;

int main() {

    sf::RenderWindow window(sf::VideoMode(resolutionWidth, resolutionHeight), "SortingAlgorithms");
    window.setFramerateLimit(framerateLimit);

    Field field(columnNumber, 0.1, 0.001, resolutionWidth, resolutionHeight);
    bool sorted = false;
    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (!sorted) {
            SortingAlgorithms::BubbleSort(field, window, event);
            sorted = true;
        }
        field.drawAllColumns(window);
        window.display();
    }
    return 0;
}

