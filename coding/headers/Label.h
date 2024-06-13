#ifndef LABEL_H
#define LABEL_H
#include <SFML/Graphics.hpp>

class Label {
    public:
        Label() {};
        Label(std::string value, sf::Font &font, int size, bool isClickable) {
            label.setString(value);
            label.setFont(font);
            label.setCharacterSize(size);
            label.setFillColor(sf::Color::Black);
        }

        void setValue(sf::String value) {
            label.setString(value);
        }

        void setPosition(sf::Vector2f pos) {
            label.setPosition(pos);
            labelBounds = label.getGlobalBounds();
        }

        void drawTo(sf::RenderWindow &window) {
            window.draw(label);
        }

        bool mouseOver(sf::RenderWindow &window) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            return labelBounds.contains(static_cast<sf::Vector2f>(mousePos));
        }

        std::string getValue() {
            std::string expression = label.getString();
            size_t pos = expression.find('=');
            std::string exp = expression.substr(0, pos-1);
            return exp;
        }

    private:
        sf::Text label;
        sf::FloatRect labelBounds;
};

#endif