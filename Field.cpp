//
// Created by max on 02.11.2021.
//

#include "Field.h"

Field::Field(float colNumber,
             float gapWidth,
             float gapEdgesWidth,
             float resolutionWidth,
             float resolutionHeight) {
    columns.resize(static_cast<int>(colNumber));
    numbers.resize(static_cast<int>(colNumber));
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

void Field::drawAllColumns(sf::RenderWindow &window) {
    for (Column& rect : columns) {
        window.draw(rect.cell);
    }
};

std::vector<Column> Field::getColumns() {
    return this->columns;
};

Column Field::operator[](const int index) {
    return columns[index];
};