#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESC_KEY 27 

class Textbox {
public:
    Textbox() { }
    Textbox(int size, sf::Color color, bool sel, float width, float height) {
        textbox.setCharacterSize(size);
        textbox.setFillColor(color); 
        isSelected = sel;
        if (sel) {
            textbox.setString("_");
        } else {
            textbox.setString("");
        }
        background.setSize(sf::Vector2f(width, height));
        background.setOutlineThickness(1);
        background.setOutlineColor(sf::Color::Black);
    }

    void setFont(sf::Font &font) {
        textbox.setFont(font);
    }

    void setPosition(sf::Vector2f pos) {
        textbox.setPosition(pos);
        background.setPosition(pos);
    }

    void setColor(sf::Color color) {
        background.setFillColor(color);
    }

    void setLimit(bool ToF) {
        hasLimit = ToF;
    }

    void setLimit(bool ToF, int lim) {
        hasLimit = ToF;
        limit = lim;
    }

    void setValue(std::string value) {
        text.str("");
        text << value;
        textbox.setString(value + (isSelected ? "_" : ""));
    }

    void setSelected(bool sel) {
        isSelected = sel;
        if (!sel) {
            std::string t = text.str();
            std::string newT = "";
            for (int i = 0; i < t.length(); i++) {
                newT += t[i];
            }
            textbox.setString(newT);
        } else {
            textbox.setString(text.str() + "_");
        }
    }

    bool mouseOver(sf::RenderWindow &window) {
            float mouseX = sf::Mouse::getPosition(window).x;
            float mouseY = sf::Mouse::getPosition(window).y;

            float btnPosX = background.getPosition().x;
            float btnPosY = background.getPosition().y;

            float btnxPosWidth = background.getPosition().x + background.getLocalBounds().width;
            float btnyPosHeight = background.getPosition().y + background.getLocalBounds().height;

            if (mouseX < btnxPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
                return true;
            }
            return false;
    }

    std::string getText() {
        return text.str();
    }

    void drawTo(sf::RenderWindow &window) {
        window.draw(background);
        window.draw(textbox);
    }

    void typedOn(sf::Event input) {
        if (isSelected) {
            int charTyped = input.text.unicode;
            if (charTyped < 128) {
                if (hasLimit) {
                    if (text.str().length() <= limit) {
                        inputLogic(charTyped);
                    } else if (text.str().length() > limit && charTyped == DELETE_KEY) {
                        deleteLastChar();
                    }
                } else {
                    inputLogic(charTyped);
                }
            }
        }
    }

private:
    sf::Text textbox;
    std::ostringstream text;
    sf::RectangleShape background;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

    void inputLogic(int charTyped) {
        if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESC_KEY) {
            text << static_cast<char>(charTyped);
        } else if (charTyped == DELETE_KEY) {
            if (text.str().length() > 0) {
                deleteLastChar();
            }
        }
        textbox.setString(text.str() + "_");
    }

    void deleteLastChar() {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length() - 1; i++) {
            newT += t[i];
        }
        text.str("");
        text << newT;
        textbox.setString(text.str() + "_");
    }
};

#endif