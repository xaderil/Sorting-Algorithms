#include "SortingAlgorithms.h"

void SortingAlgorithms::BubbleSort(Field &field, sf::RenderWindow &window, sf::Event& event) {
    for(int i = 0; i < field.getColumns().size(); i++) {
        for(int j = 0; j < field.getColumns().size() - 1; j++) {
            if (field.getColumns()[j].index > field.getColumns()[j+1].index) {
                std::swap(field[j].index, field[j+1].index);
                window.clear();
                sf::Event event{};
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }
                field.setColumnPosition(field[j]);
                field.setColumnPosition(field[j+1]);
                field[j].cell.setFillColor(sf::Color::Red);
                field.drawAllColumns(window);
                window.display();
//                std::this_thread::sleep_for(std::chrono::milliseconds (100));
                field[j].cell.setFillColor(sf::Color::White);
            } else {
                continue;
            }
        }
    }
}