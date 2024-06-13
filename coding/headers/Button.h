#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Button {
    public:
        Button(){};
        Button(std::string value, sf::Font &font) {
             label.setString(value);
             label.setFont(font);
             label.setCharacterSize(25);
             label.setFillColor(sf::Color::Black);
             button.setSize(sf::Vector2f(150, 40));
             button.setOutlineColor(sf::Color::Black);
             button.setOutlineThickness(1);
        }

        void setPosition(sf::Vector2f pos) {
            double textPosition = button.getPosition().x + (button.getSize().x / 2.0) - (label.getLocalBounds().width / 2.0);
            std::cout << "Tamano de string: " << textPosition << std::endl;
            button.setPosition(pos);
            label.setPosition(pos.x + textPosition, pos.y + 2);
        }

        void drawtTo(sf::RenderWindow &window) {
            window.draw(button);
            window.draw(label);
        }

        bool mouseOver(sf::RenderWindow &window) {
            float mouseX = sf::Mouse::getPosition(window).x;
            float mouseY = sf::Mouse::getPosition(window).y;

            float btnPosX = button.getPosition().x;
            float btnPosY = button.getPosition().y;

            float btnxPosWidth = button.getPosition().x + button.getLocalBounds().width;
            float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;

            if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
                return true;
            }
            return false;
        }

    private:
        sf::RectangleShape button;
        sf::Text label;
};

#endif