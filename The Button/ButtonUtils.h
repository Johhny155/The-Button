//
// Created by Xavier Jones on 4/10/26.
//

#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <functional>

namespace ButtonUtils {

    using ButtonEvent = std::function<void(sf::CircleShape&, const sf::RenderWindow&)>;

    void moveButtonRandomly(sf::CircleShape& button, const sf::RenderWindow& window);
    void changeButtonColor(sf::CircleShape& button);
    void playRandomSound();

    ButtonEvent getRandomEvent();

}