/* Hello, this program makes a graphic of a button and when pressed, it chooses a random number
 * that is connected to a function to make funny stuff happen.
 * Created April 10th, 2026 by Xavier Jones and John Wilson
 * Version 0.55
 */

#include <iostream>
#include <random> // used to randomly pick events for every click.
#include <SFML/Graphics.hpp> // this is for graphics, had to install it separately.
#include "ButtonUtils.h" // header file with all those functions
#include <filesystem>
using namespace std;

int main() {

    std::cout << std::filesystem::current_path() << std::endl; // where the working directory is

    int clickCount = 0;

    // CLICK MILESTONES
    bool ten_clicks = false;
    bool fifty_clicks = false;
    bool hundred_clicks = false;

    // Create the window
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "The Button", sf::Style::Fullscreen);

    // Create the red button
    sf::CircleShape button(60);
    button.setFillColor(sf::Color::Red);

    // Position the button
    button.setOrigin(60, 60); // radius of circle
    sf::Vector2u size = window.getSize();
    button.setPosition(size.x / 2.f, size.y / 2.f);

    // Create text and font and position it
    sf::Text text;
    sf::Font font;
    font.loadFromFile("/System/Library/Fonts/Supplemental/Arial.ttf");
    text.setFont(font);
    text.setString("Click the Button!");
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::White);
    text.setPosition(250.f, 50.f);

    bool showText = true; // lets the text be visible until button is clicked

    // creates the text for the counter
    sf::Text counterText;
    counterText.setFont(font);
    counterText.setCharacterSize(24);
    counterText.setFillColor(sf::Color::White);

    // ===== EXIT BUTTON =====
    sf::RectangleShape exitButton(sf::Vector2f(40.f, 40.f));
    exitButton.setFillColor(sf::Color(200, 0, 0)); // dark red
    exitButton.setPosition(10.f, 10.f);

    sf::Text exitText;
    exitText.setFont(font);
    exitText.setString("X");
    exitText.setCharacterSize(28);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(20.f, 10.f);

// ===== MAIN GAME LOOP =====
while (window.isOpen()) {
    // do something while window is open
    sf::Event event;

    counterText.setString("Clicks: " + std::to_string(clickCount)); // set counter to this string

    // position counter text
    sf::Vector2u windowSize = window.getSize();

    sf::FloatRect textBounds = counterText.getLocalBounds();

    counterText.setPosition(
        windowSize.x - textBounds.width - 40,
        windowSize.y - textBounds.height - 35
    );

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) // if window is closed, close window
            window.close();

        // Detect clicks
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {

                // get mouse position
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                // Check if the mouse is within the button, if so, then do something cool.
                if (button.getGlobalBounds().contains(mousePos.x, mousePos.y)) {

                    // === these play every click ===
                    showText = false; // hide the text when button is clicked
                    ButtonUtils::playRandomSound();
                    clickCount++; // adds a click to the counter
                    // ================================

                    // ===== functions are drawn randomly below =====
                    ButtonUtils::ButtonEvent event = ButtonUtils::getRandomEvent();
                    event(button, window);
                }

                // Check exit button click
                if (exitButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    window.close();
                }
            }
        }
    }

    if (clickCount == 10 && ten_clicks == false) {
        cout << "Reached 10 Clicks!" << endl;
        ten_clicks = true;
    }

    if (clickCount == 50 && fifty_clicks == false) {
        cout << "Reached 50 Clicks!" << endl;
        fifty_clicks = true;
    }

    if (clickCount == 100 && hundred_clicks == false) {
        cout << "Reached 100 Clicks!" << endl;
        hundred_clicks = true;
    }

    // Draw everything
    window.clear(sf::Color::Black); // background is black
    window.draw(button); // Draws the button
    if (showText) {
        window.draw(text);
    }
    window.draw(counterText);
    window.draw(exitButton);
    window.draw(exitText);
    window.display();
}
    return 0;
}