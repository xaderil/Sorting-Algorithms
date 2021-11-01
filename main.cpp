#include <SFML/Graphics.hpp>
#include <iostream>
#include <numeric>
#include <vector>

const uint32_t resolutionWidth = 1280.f;
const uint32_t resolutionHeight = 720.f;
const uint32_t framerateLimit = 90;

struct Column {
    Column() {};
    Column(unsigned int ind, sf::RectangleShape&& rect) : index(ind), cell(rect) {};
    unsigned int index;
    sf::RectangleShape cell;
};
class Field {
public:
    Field(unsigned int colNumber, float gapWidth = 0.05, float gapEdgesWidth = 0.02){
        columns.resize(colNumber);
        numbers.resize(colNumber);
        std::iota(numbers.begin(), numbers.end(), 0);
        for (unsigned i = 0; i < colNumber; i++) {
            float neededResolution = resolutionWidth - gapEdgesWidth * resolutionWidth;
            float resolutionCell = neededResolution/colNumber - neededResolution/colNumber * gapWidth;
            float colWidth = resolutionCell;
            float colHeight = i * resolutionHeight/colNumber + resolutionHeight/colNumber - gapWidth*resolutionHeight/colNumber*2;
            columns[i] = Column(i, sf::RectangleShape({colWidth, colHeight}));
            columns[i].cell.setPosition(i*neededResolution/colNumber + gapEdgesWidth*resolutionWidth/2 + gapWidth*resolutionCell/2, resolutionHeight - colHeight);

        }
    }

    void drawColumns() {

    }
    void drawAllColumns(sf::RenderWindow& window) {
        for (Column& rect : columns) {
            window.draw(rect.cell);
        }
    }

    std::vector<Column> getColumns() {
        return this->columns;
    }

    Column operator [] (const int index) {
        return columns[index];
    };

private:
    std::vector<Column> columns;
    std::vector<int> numbers;
};

class SortingAlgorithms {
public:
    static void BubbleSort(Field& field, sf::RenderWindow& window) {
        for(int i = 0; i < field.getColumns().size(); i++) {
            for(int j = 0; j < field.getColumns().size() - 1; j++) {
                if (field.getColumns()[i].index > field.getColumns()[j+1].index) {
                    std::swap(field.getColumns()[i].index, field.getColumns()[j+1].index);
                    field.drawAllColumns(window);
                } else {
                    continue;
                }
            }
        }
    }
};


int main() {
    sf::RenderWindow window(sf::VideoMode(resolutionWidth, resolutionHeight), "SortingAlgorithms");
    window.setFramerateLimit(framerateLimit);

    Field field(50, 0.1, 0.001);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        field.drawAllColumns(window);
        window.display();
    }
    return 0;
}

