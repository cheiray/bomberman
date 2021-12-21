#include <SFML/Graphics.hpp>
#include "bomb.h"
#include "detruireCase.h"
#include "detruireJoueur.h"

void place_bomb(sf::Vector2f joueur, sf::Sprite& bombe)
{
    joueur.y = joueur.y + 30;
    joueur.x = joueur.x + 25;
    int posX;
    posX= joueur.x / TAILLE_CASE;
    int posY;
    posY =   joueur.y / TAILLE_CASE;
    
    bombe.setPosition(posX * TAILLE_CASE, posY * TAILLE_CASE);
}





void diparition_bomb(sf::Sprite& bombe, float &dtBomb, int& nbBomb, sf::Clock& clockBomb, sf::Vector3f destroyableTile[],int maplevel[], sf::Sprite& joueur, sf::Texture &textureDead, sf::Sprite& joueur2, sf::Texture& textureDead2, sf::RenderWindow& window,int remoteExplode)
{
    sf::Time elapsed = clockBomb.getElapsedTime();

    /*if (elapsed.asSeconds() - dtBomb >= 3)
    {
        sf::Vector2f posBombe = bombe.getPosition();
        detruireCase(posBombe.x,posBombe.y,destroyableTile,maplevel);
        detruireJoueur(posBombe.x, posBombe.y, joueur,textureDead,joueur2,textureDead2,window);
        dtBomb = elapsed.asSeconds();
        bombe.setPosition(-100, -100);
        nbBomb=0;
    }*/
    if (remoteExplode==1)
    {
        sf::Vector2f posBombe = bombe.getPosition();
        detruireCase(posBombe.x, posBombe.y, destroyableTile, maplevel);
        detruireJoueur(posBombe.x, posBombe.y, joueur, textureDead, joueur2, textureDead2, window);
        bombe.setPosition(-100, -100);
        remoteExplode = 0;
        nbBomb = 0;
    }
}

