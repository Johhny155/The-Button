//
// Created by Xavier Jones on 4/10/26.
//

#include "ButtonUtils.h" // includes the header file
#include <random>
#include <vector>
#include <SFML/Audio.hpp> // audio module
#include <iostream>

namespace ButtonUtils {
    void moveButtonRandomly(sf::CircleShape& button, const sf::RenderWindow& window) {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        float radius = button.getRadius();
        sf::Vector2u size = window.getSize(); // gets the window size

        // Defines bounds so the button doesnt go off the screen
        std::uniform_real_distribution<float> xDist(radius, size.x - radius);
        std::uniform_real_distribution<float> yDist(radius, size.y - radius);

        button.setPosition(xDist(gen), yDist(gen));
    }

    void changeButtonColor(sf::CircleShape& button) {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> colorDist(0, 5);
        int choice = colorDist(gen);

        switch (choice) {
            case 0: button.setFillColor(sf::Color::Red); break;
            case 1: button.setFillColor(sf::Color::Blue); break;
            case 2: button.setFillColor(sf::Color::Green); break;
            case 3: button.setFillColor(sf::Color::Yellow); break;
            case 4: button.setFillColor(sf::Color::Magenta); break;
            case 5: button.setFillColor(sf::Color::Cyan); break;
        }
    }

    void playRandomSound() {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        static std::vector<std::string> soundFiles = {
            "sounds/sound1.wav",
            "sounds/sound2.wav",
            "sounds/sound3.wav"
        };

        static std::vector<sf::SoundBuffer> buffers(soundFiles.size());
        static std::vector<std::unique_ptr<sf::Sound>> activeSounds;
        static bool loaded = false;

        if (!loaded) {
            for (size_t i = 0; i < soundFiles.size(); i++) {
                buffers[i].loadFromFile(soundFiles[i]);
            }
            loaded = true;
        }

        std::uniform_int_distribution<int> dist(0, soundFiles.size() - 1);
        int index = dist(gen);

        auto sound = std::make_unique<sf::Sound>();
        sound->setBuffer(buffers[index]);
        sound->play();

        activeSounds.push_back(std::move(sound));

        activeSounds.erase(
            std::remove_if(activeSounds.begin(), activeSounds.end(),
                [](const std::unique_ptr<sf::Sound>& s) {
                    return s->getStatus() == sf::Sound::Stopped;
                }),
            activeSounds.end()
        );
    }


    // ========== !!! Put all new functions above this one !!! ==========

    ButtonEvent getRandomEvent() {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        // Vector to put each function in...for randomizing
        static std::vector<ButtonEvent> events = {

            [](sf::CircleShape& b, const sf::RenderWindow& w) {
                moveButtonRandomly(b, w);
            },

            [](sf::CircleShape& b, const sf::RenderWindow&) {
                changeButtonColor(b);
            },
        };

        std::uniform_int_distribution<int> dist(0, events.size() - 1);
        return events[dist(gen)];
    }
}