#include "Field.h"

Field::Field(float colNumber,
             float gapWidth,
             float gapEdgesWidth,
             float resolWidth,
             float resolHeight) :
             numberOfColumns(colNumber),
             columnsGap(gapWidth),
             edgesGap(gapEdgesWidth),
             resolutionWidth(resolWidth),
             resolutionHeight(resolHeight) {
    columns.resize(static_cast<int>(numberOfColumns));
    resolutionWithoutEdges = resolutionWidth - edgesGap * resolutionWidth;
    widthOfCell = resolutionWithoutEdges/numberOfColumns - resolutionWithoutEdges/numberOfColumns * columnsGap;
    for (int i = 0; i < numberOfColumns; i++) {
        float heightOfCell = i * resolutionHeight/numberOfColumns + resolutionHeight/numberOfColumns - columnsGap*resolutionHeight/numberOfColumns*2;
        columns[i] = {static_cast<float>(i), sf::RectangleShape({widthOfCell, heightOfCell})};
        setColumnPosition(columns[i]);
    }
}

void Field::drawAllColumns(sf::RenderWindow &window) {
    for (Column& rect : columns) {
        window.draw(rect.cell);
    }
};

void Field::randomizeColumns() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(columns.begin(), columns.end(), std::default_random_engine(seed));
}

void Field::setColumnPosition(Column& column) {
    float heightOfCell = column.cell.getSize().y;
    auto it = std::find_if(columns.begin(), columns.end(), [column](Column& col){return col.value == column.value;});
    float indexInCellArray = static_cast<float>(it - columns.begin());
    float xPosition = indexInCellArray*resolutionWithoutEdges/numberOfColumns + edgesGap*resolutionWidth/2 + columnsGap*widthOfCell/2;
    float yPosition = resolutionHeight - heightOfCell;
    column.cell.setPosition(xPosition, yPosition);
};


std::vector<Column>& Field::getColumns() {
    return this->columns;
};

Column& Field::operator[](const int index) {
    return columns[index];
};