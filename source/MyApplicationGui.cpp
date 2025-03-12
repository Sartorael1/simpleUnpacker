#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include "../headers/MyApplicationGui.h"
#include <iostream>
#include <Windows.h>







void MyApplicationGui::initGui() {
    try {
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Test");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
        }
            window.clear();
            // Добавьте свою логику отрисовки с использованием ImGui здесь
            window.display();
    } catch  (const std::exception& e ){
        std::cout<< e.what()<<std::endl;
    }
}
