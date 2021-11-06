#include "SortingAlgorithms.h"

void SortingAlgorithms::BubbleSort(Field &field, sf::RenderWindow &window) {
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