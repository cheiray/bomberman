#include <SFML/Graphics.hpp>
#include "collisionCheck.h"
int checkPlayerPos(sf::Vector2f& player2, sf::Vector2f tilesBlocking[], char direction, char &saveLastPos, int speed, float dt)
{
    int moveTest = 1;
    sf::Vector2f player =player2;
    if (direction = 'L')
    {
        
        player.x -= speed * dt- speed * dt;
        for (int i = 0; i < 169; i++)
        {
            if (player.x + offsetOrigin >= tilesBlocking[i].x - offsetSize && player.x - offsetOrigin <= tilesBlocking[i].x + offsetSize && player.y - offsetOrigin >= tilesBlocking[i].y - offsetSize && player.y - offsetOrigin <= tilesBlocking[i].y + offsetSize)
            {
                moveTest = 0;
                printf("%i", moveTest);
            }
        }
        saveLastPos = 'L'; // This will prevent some weird glitch that made the players glide onto the walls
    }
    if (direction = 'R')
    {
        player.x += speed * dt+ speed*dt;
        for (int i = 0; i < 169; i++)
        {
            if (player.x - offsetOrigin >= tilesBlocking[i].x + offsetSize && player.x - offsetOrigin <= tilesBlocking[i].x - offsetSize && player.y - offsetOrigin >= tilesBlocking[i].y - offsetSize && player.y - offsetOrigin <= tilesBlocking[i].y + offsetSize)
            {
                moveTest = 0;
                printf("%i", moveTest);
            }
        }
        saveLastPos = 'R';
    }
    if (direction = 'U')
    {
        player.y -= speed * dt- speed * dt;
        for (int i = 0; i < 169; i++)
        {
            if (player.x - offsetOrigin >= tilesBlocking[i].x - offsetSize && player.x - offsetOrigin <= tilesBlocking[i].x + offsetSize && player.y - offsetOrigin >= tilesBlocking[i].y - offsetSize && player.y - offsetOrigin <= tilesBlocking[i].y + offsetSize)
            {
                moveTest = 0;
                printf("%i", moveTest);
            }
        }
        saveLastPos = 'U';
    }
    if (direction = 'D')
    {
        player.y += speed * dt+ speed * dt;
        for (int i = 0; i < 169; i++)
        {
            if (player.x - offsetOrigin >= tilesBlocking[i].x - offsetSize && player.x - offsetOrigin <= tilesBlocking[i].x + offsetSize && player.y - offsetOrigin >= tilesBlocking[i].y + offsetSize && player.y - offsetOrigin <= tilesBlocking[i].y - offsetSize)
            {
                moveTest = 0;
                printf("%i", moveTest);
            }
        }
        saveLastPos = 'D';
    }

    return moveTest;

}

/*int checkPlayerPos(sf::Vector2f& player, sf::Vector2f tilesBlocking[])
{
    int movability = 1;
    sf::Texture colision1Texture;
    sf::Texture colision2Texture;
    if (!colision1Texture.loadFromFile("J1Back1.png"))
        printf("PB de chargement de l'image !\n");
    if (!colision2Texture.loadFromFile("Caisse.png"))
        printf("PB de chargement de l'image !\n");
    sf::Sprite colision1;
    sf::Sprite colision2;
    colision1.setTexture(colision1Texture);
    colision2.setTexture(colision2Texture);
    colision1.setPosition(player);
    for (int i = 0; i < 20; i++)
    {
        colision2.setPosition(tilesBlocking[i]);
        if (colision1.getGlobalBounds().intersects(colision2.getGlobalBounds()))
        {
            movability=0;
        }
    }
    return movability;


}*/