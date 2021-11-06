#include "Field.h"

Field::Field(float colNumber,
             float gapWidth,
             float gapEdgesWidth,
             float resolWidth,
             float resolHeight) : numberOfColumns(colNumber), columnsGap(gapWidth), edgesGap(gapEdgesWidth), resolutionWidth(resolWidth), resolutionHeight(resolHeight){
    columns.resize(static_cast<int>(numberOfColumns));
//    numbers.resize(static_cast<int>(colNumber));
//    std::iota(numbers.begin(), numbers.end(), 0);
    resolutionWithoutEdges = resolutionWidth - edgesGap * resolutionWidth;
    widthOfCell = resolutionWithoutEdges/numberOfColumns - resolutionWithoutEdges/numberOfColumns * columnsGap;
    for (int i = 0; i < numberOfColumns; i++) {
        float heightOfCell = i * resolutionHeight/numberOfColumns + resolutionHeight/numberOfColumns - columnsGap*resolutionHeight/numberOfColumns*2;
        columns[i] = {static_cast<float>(i), sf::RectangleShape({widthOfCell, heightOfCell})};
        randomizeColumns();
        setColumnPosition(columns[i]);
    }
}

void Field::drawAllColumns(sf::RenderWindow &window) {
    for (Column& rect : columns) {
        window.draw(rect.cell);
    }
};

void Field::randomizeColumns() {
    std::vector<int> indices(numberOfColumns);
    std::random_device rd;
    std::mt19937 g(rd());
    std::iota(indices.begin(), indices.end(), 0);
    std::shuffle(indices.begin(), indices.end(), g);
    for(int i = 0; i < numberOfColumns; i++) {
        columns[i].index = static_cast<float>(indices[i]);
    }
}

void Field::setColumnPosition(Column& column) {
    float heightOfCell = column.cell.getSize().y;
    column.cell.setPosition(column.index*resolutionWithoutEdges/numberOfColumns + edgesGap*resolutionWidth/2 + columnsGap*widthOfCell/2, resolutionHeight - heightOfCell);
};


std::vector<Column>& Field::getColumns() {
    return this->columns;
};

Column& Field::operator[](const int index) {
    return columns[index];
};