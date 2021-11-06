#include <SFML/Graphics.hpp>
#include <iostream>
#include <numeric>
#include <vector>
#include <random>
#include <thread>
#include <chrono>

struct Column {
    float index{};
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
        void setColumnPosition(Column& column);
        void randomizeColumns();

        std::vector<Column>& getColumns();

        Column& operator [] (int index);

    private:
        std::vector<Column> columns;
//        std::vector<int> numbers;
        float numberOfColumns;
        float resolutionWithoutEdges;
        float widthOfCell;
        float columnsGap;
        float edgesGap;
        float resolutionWidth;
        float resolutionHeight;
};

