#pragma once
#define offsetSize 35
#define offsetOrigin 0

int checkPlayerPos(sf::Vector2f& player, sf::Vector2f tilesBlocking[], char direction, char &saveLastPos, int speed, float dt);