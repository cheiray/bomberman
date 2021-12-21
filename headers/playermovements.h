#pragma once


void move_left(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtUp, int& firstmov);
void move_right(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtUp, int& firstmov);
void move_up(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtUp, int& firstmov);
void move_down(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtDown, int& firstmov);

