//
// Created by Xavier Jones on 4/10/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

namespace ButtonUtils {

    using ButtonEvent = std::function<void(sf::CircleShape&, const sf::RenderWindow&, const sf::Vector2i&)>;

    void moveButtonRandomly(sf::CircleShape& button, const sf::RenderWindow& window);
    void changeButtonColor(sf::CircleShape& button);
    void playRandomSound();
    void changeCursor(const sf::RenderWindow& window, const sf::Vector2i mpos);

    ButtonEvent getRandomEvent();

}