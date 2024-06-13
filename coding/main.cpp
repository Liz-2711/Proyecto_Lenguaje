#include <iostream>
#include <SFML/Graphics.hpp>
#include "./headers/Textbox.h"
#include "./headers/Label.h"
#include "./headers/Button.h"
#include "./headers/Lexer.h"
#include "./headers/Parser.h"
#include "./headers/Configuracion.h"
#include "./headers/Evaluador.h"
#include "./headers/Memoria.h"
#include "./headers/Historial.h"

using namespace sf;

int main() {
    sf::RenderWindow window(sf::VideoMode(1920,1080), "Evaluador de Expresiones");

    Configuracion configuracion("./config/constantes.txt");
    Evaluador evaluador;
    Memoria memoria;
    Historial historial;

    vector<Label> historyLabels;

    Font arial;
    arial.loadFromFile("arial.ttf");

    //Variables
    string expression = "";
    string error = "";
    float windowWidth = 1920.0f;
    float windowHeight = 1080.0f;

    float padding = 20.0f;
    float rectW = (windowWidth - 4 * padding) / 3;
    float rectH = 1040.0f;

    //Fondo
    RectangleShape background(sf::Vector2f(windowWidth, windowHeight));
    background.setPosition(0, 0);
    background.setFillColor(Color::White);

    //Container de Constantes
    RectangleShape constContainer(sf::Vector2f(rectW, rectH));
    constContainer.setPosition(padding, 20);
    constContainer.setFillColor(sf::Color::White);
    constContainer.setOutlineThickness(2);
    constContainer.setOutlineColor(Color::Black);

    //Container de Expresiones
    RectangleShape expContainer(sf::Vector2f(rectW, rectH));
    expContainer.setPosition(2 * padding + rectW, 20);
    expContainer.setFillColor(sf::Color::White);
    expContainer.setOutlineThickness(2);
    expContainer.setOutlineColor(Color::Black);

    //Tercer container
    RectangleShape varContainer(sf::Vector2f(rectW, rectH));
    varContainer.setPosition(3 * padding + 2 * rectW, 20);
    varContainer.setFillColor(sf::Color::White);
    varContainer.setOutlineThickness(2);
    varContainer.setOutlineColor(Color::Black);

    //Labels
    Label constLabel("Constantes", arial, 25, false);
    constLabel.setPosition({padding + 20, 50});

    Label expLabel("Ingreso de Expresion", arial, 25, false);
    expLabel.setPosition({(2 * padding + rectW) + 20, 50});

    Label varLabel("Variables", arial, 25, false);
    varLabel.setPosition({(3 * padding + 2 * rectW) + 20, 50});

    Label histLabel("Historial", arial, 25, false);
    histLabel.setPosition({(2 * padding + rectW) + 20, 500});

    Label resultLabel("", arial, 25, false);
    resultLabel.setPosition({700, 280});

    //Inputs de texto
    Textbox expTB(30, Color::Black, false, rectW - 40, 100.0f);
    expTB.setFont(arial);
    expTB.setPosition({2 * padding + rectW + 20, 100});
    expTB.setColor(Color::White);

    Textbox varTB(30, Color::Black, false, rectW - 40, 100.0f);
    varTB.setFont(arial);
    varTB.setPosition({3 * padding + 2 * rectW + 20, 100});
    varTB.setColor(Color::White);

    //Botones
    Button expButton("Evaluar", arial);
    expButton.setPosition({1095, 220});
    Button varButton("Crear", arial);
    varButton.setPosition({1720, 220});
    
    //Labels de contantes
    vector<Label> contantLabels;
    int index = 0; 
    for (const auto &c : configuracion.obtenerConstantes()) {
        string constant = c.first + ": " + to_string(c.second);
        cout << constant << endl;
        Label constLabel(constant, arial, 25, false);
        constLabel.setPosition(sf::Vector2f(50, 100 + index * 25));
        contantLabels.push_back(constLabel);
        index++;
    }

    while (window.isOpen()) {
        Event event;

        while (window.pollEvent(event)) {
            switch(event.type) {
                case Event::Closed: 
                    window.close();
                case Event::TextEntered: 
                    expTB.typedOn(event);
                    varTB.typedOn(event);
                    break;
                case Event::MouseButtonPressed: 
                    if (expButton.mouseOver(window)) {
                        expression = expTB.getText();
                        cout << "Expresion: " << expression << std::endl;
                        
                        error = lexer(expression, configuracion);

                        if (error.empty()) {
                            string result = evaluador.evaluar(tokensTemp, memoria, configuracion);
                                resultLabel.setValue(result);
                                historial.agregar(expression, result);
                                int index2 = 0; 
                                for (const auto &c : historial.obtenerHistorial()) {
                                    string constant = c;
                                    Label historyLabel(constant, arial, 25, true);
                                    historyLabel.setPosition(sf::Vector2f(680, 550 + index2 * 25));
                                    historyLabels.push_back(historyLabel);
                                    index2++;
                                }
                                for (string s : historial.obtenerHistorial()) {
                                    cout << s << endl;
                                }
                        } else {
                            resultLabel.setValue(error);
                        }
                        
                    }
                    else if(varButton.mouseOver(window)) {
                        std::cout << varTB.getText() << endl;
                    }
                    else if (expTB.mouseOver(window)) {
                        varTB.setSelected(false);
                        expTB.setSelected(true);
                    } 
                    else if (varTB.mouseOver(window)) {
                        expTB.setSelected(false);
                        varTB.setSelected(true);
                    }
                    break;
            }

            for (Label &hist : historyLabels) {
                if (event.type == Event::MouseButtonPressed) {
                    if(hist.mouseOver(window)) {
                        expression = hist.getValue();
                        cout << expression << endl;
                        expTB.setValue(expression);
                    }
                }
            }
        }

        

        window.clear();
        
        
        window.draw(background);
        window.draw(constContainer);
        window.draw(expContainer);
        window.draw(varContainer);
        expTB.drawTo(window);
        varTB.drawTo(window);
        constLabel.drawTo(window);
        expLabel.drawTo(window);
        varLabel.drawTo(window);
        histLabel.drawTo(window);
        resultLabel.drawTo(window);
        expButton.drawtTo(window);
        varButton.drawtTo(window);
        for (Label &label : contantLabels) {
            label.drawTo(window);
        }

        for (Label &hist : historyLabels) {
            hist.drawTo(window);
        }
        window.display();
    }
    return 0;
}