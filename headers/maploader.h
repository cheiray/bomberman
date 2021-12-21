#pragma once
// source
#define NBRTILE0 5
#define NBRTILE1 9
#define NBRTILE2 1
#define NBRTILE3 5
#define NBRTILE4 1
#define SIZETILES 50   // en pixel
typedef struct
{
    int posX;
    int posY;

}TypeTile;

void mapLoader(sf::RenderTexture& target, int mapLevel[], sf::Vector3f destroyableTile[], sf::Vector2f tilesBlocking[]);