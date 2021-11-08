#include "SortingAlgorithms.h"

void SortingAlgorithms::BubbleSort(Field &field, sf::RenderWindow &window, sf::Event& event) {
    for(int i = 0; i < field.getColumns().size(); i++) {

        window.clear();
        for(int j = 0; j < field.getColumns().size() - 1 - i; j++) {
            sf::Event event{};
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (field[j].value > field[j+1].value) {
                std::swap(field[j], field[j+1]);
                field.setColumnPosition(field[j]);
                field.setColumnPosition(field[j+1]);
//                field[j].cell.setFillColor(sf::Color::Red);

//                field[j].cell.setFillColor(sf::Color::White);
            } else {
                continue;
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds (0));
        field.drawAllColumns(window);
        window.display();
    }
}