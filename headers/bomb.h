#include <SFML/Graphics.hpp>
#include <stdio.h>

#define TAILLE_CASE 50
#define TEMPS_EXPLOSION 3
#define FRAMERATE 60
#define SIZETILES 50   // en pixel

void place_bomb(sf::Vector2f joueur, sf::Sprite& bombe);
void diparition_bomb(sf::Sprite& bombe, float &dtBomb, int& nbBomb, sf::Clock& clockBomb, sf::Vector3f destroyableTile[], int mapLevel[], sf::Sprite& joueur, sf::Texture& textureDead, sf::Sprite& joueur2, sf::Texture& textureDead2, sf::RenderWindow& window, int remoteExplode);
