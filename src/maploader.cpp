#include <SFML/Graphics.hpp>
#include "maploader.h" 




void mapLoader(sf::RenderTexture& target, int level[], sf::Vector3f destroyableTile[], sf::Vector2f tilesBlocking[])
{

    sf::Texture textureTile0;
    sf::Texture textureTile1;
    sf::Texture textureTile2;
    sf::Texture textureTile3;
    sf::Texture textureTile4;
    if (!textureTile0.loadFromFile("plancher.png"))
        printf("PB de chargement de l'image !\n");
    if (!textureTile1.loadFromFile("plancher.png"))
        printf("PB de chargement de l'image !\n");
    if (!textureTile2.loadFromFile("Mur.png"))
        printf("PB de chargement de l'image !\n");
    if (!textureTile3.loadFromFile("Caisse.png"))
        printf("PB de chargement de l'image !\n");
    if (!textureTile4.loadFromFile("case_spe.png"))
        printf("PB de chargement de l'image !\n");
   
  
    sf::Sprite tile0[100];
    sf::Sprite tile1[100] ;
    sf::Sprite tile2[100] ;
    sf::Sprite tile3[100] ;
    sf::Sprite tile4[1];
   // sf::Sprite tile4[NBRTILE4] = {};
    int i;
    int posX;
    int posY;
    int tile0Round = 0, tile1Round = 0, tile2Round = 0, tile3Round = 0, tile4Round = 0; // permet de connaitre la bonne case du tableau

    for (i = 0; i <= 168; i++) {
        posY = i / 13;
        posX = i % 13;
        switch (level[i])
        {
        case 0: 
            tile0[tile0Round].setTexture(textureTile0);
            tile0[tile0Round].setPosition(posX * SIZETILES, posY * SIZETILES);
            tile0Round++;
            break;
        case 1: 
            tile1[tile1Round].setTexture(textureTile1);
            tile1[tile1Round].setPosition(posX * SIZETILES, posY * SIZETILES);
            tile1Round++;
            break;
        case 2: 
            tile2[tile2Round].setTexture(textureTile2);
            tile2[tile2Round].setPosition(posX * SIZETILES, posY * SIZETILES);
            tilesBlocking[tile2Round + tile3Round + tile4Round].x = posX * SIZETILES;
            tilesBlocking[tile2Round + tile3Round + tile4Round].y = posY * SIZETILES;
            tile2Round++;
            break;
        case 3:
            tile3[tile3Round].setTexture(textureTile3);
            tile3[tile3Round].setPosition(posX * SIZETILES, posY * SIZETILES);
            destroyableTile[tile3Round].x = posX * SIZETILES;
            destroyableTile[tile3Round].y = posY * SIZETILES; // jusqu'à +SIZETILES
            destroyableTile[tile3Round].z = i;
            tilesBlocking[tile2Round + tile3Round + tile4Round].x = posX * SIZETILES;
            tilesBlocking[tile2Round + tile3Round + tile4Round].y = posY * SIZETILES;
            tile3Round++;
            break;
        case 4:
            tile4[tile4Round].setTexture(textureTile4);
            tile4[tile4Round].setPosition(posX * SIZETILES, posY * SIZETILES);
            tilesBlocking[tile2Round + tile3Round + tile4Round].x = posX * SIZETILES;
            tilesBlocking[tile2Round + tile3Round + tile4Round].y = posY * SIZETILES;
            tile4Round++;
            break;
        default:
            break;
        }
    }
    target.clear(sf::Color::White);
    for(i=0;i<tile0Round; i++)
    target.draw(tile0[i], sf::BlendAlpha);
    for (i = 0; i < tile1Round; i++)
        target.draw(tile1[i], sf::BlendAlpha);
    for (i = 0; i < tile2Round; i++)
        target.draw(tile2[i], sf::BlendAlpha);
    for (i = 0; i < tile3Round; i++)
        target.draw(tile3[i], sf::BlendAlpha);
   for (i = 0;  i < tile4Round; i++)
        target.draw(tile4[i]);
    target.display();
    
}

