#include <SFML/Graphics.hpp>
#include <iostream>
#include <numeric>
#include <vector>

struct Column {
    Column() {};
    Column(unsigned int ind, sf::RectangleShape&& rect) : index(ind), cell(rect) {};
    unsigned int index;
    sf::RectangleShape cell;
};

class Field {
    public:
        explicit Field(float colNumber,
                       float gapWidth = 0.05,
                       float gapEdgesWidth = 0.02,
                       float resolutionWidth = 1280,
                       float resolutionHeight = 720);
        void drawAllColumns(sf::RenderWindow& window);
        Column operator [] (int index);
        std::vector<Column> getColumns();

    private:
        std::vector<Column> columns;
        std::vector<int> numbers;
};

