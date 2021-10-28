#include <SFML/Graphics.hpp>
#include <iostream>

const uint32_t resolutionWidth = 1280.f;
const uint32_t resolutionHeight = 720.f;
const uint32_t framerateLimit = 90;

class Field {
public:
    Field(unsigned int colNumber, float gapWidth = 0.05, float gapEdgesWidth = 0.02){
        columnsNumber = colNumber;
        columns.resize(colNumber);
        for (int i = 0; i < colNumber; i++) {
            float neededResolution = resolutionWidth - gapEdgesWidth * resolutionWidth;
            float resolutionCell = neededResolution/colNumber - neededResolution/colNumber * gapWidth;
            float colWidth = resolutionCell;
            float colHeight = i * resolutionHeight/colNumber + resolutionHeight/colNumber - gapWidth*resolutionHeight/colNumber*2;
            columns[i] = sf::RectangleShape({colWidth, colHeight});
            columns[i].setPosition(i*neededResolution/colNumber + gapEdgesWidth*resolutionWidth/2 + gapWidth*resolutionCell/2, resolutionHeight - colHeight);

        }
    }
    void drawColumns(sf::RenderWindow& window) {
        for (sf::RectangleShape& rect : columns) {
            window.draw(rect);
        }
    }
private:
    std::vector<sf::RectangleShape> columns;
    unsigned int columnsNumber;
};


int main() {
    sf::RenderWindow window(sf::VideoMode(resolutionWidth, resolutionHeight), "SortingAlgorithms");
    window.setFramerateLimit(framerateLimit);

    Field field(512, 0.6, 0.01);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        field.drawColumns(window);
        window.display();
    }
    return 0;
}

