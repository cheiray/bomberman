#include <SFML/Graphics.hpp>
#include "detruireJoueur.h"
#include "menu.h"
#include "bomb.h"

/*void detruireJoueur(int posBombeX, int posBombeY, sf::Sprite& joueur, sf::Texture& textureDead, sf::Sprite& joueur2, sf::Texture& textureDead2,sf::RenderWindow &window)
{

	int posX, posY;
	int posX2, posY2;
	sf::Vector2f pos = joueur.getPosition();
	sf::Vector2f pos2 = joueur2.getPosition();
	posX = pos.x;
	posY = pos.y;
	posX2 = pos2.x;
	posY2 = pos2.y;
	if (posX >= posBombeX - 50 && posX <= posBombeX + 50 && posY >= posBombeY - 25 && posY <= posY + 25)
	{
		joueur.setTexture(textureDead2);
		printf("Dead\n");
		menu(window, 1);
		
	
	}
	if (posX2 >= posBombeX - 50 && posX2 <= posBombeX + 50 && posY2 >= posBombeY - 25 && posY2 <= posY2 + 25)
	{
		
		joueur2.setTexture(textureDead);
		printf("Dead\n");
		menu(window, 2);


	}
}*/


void detruireJoueur(int posBombeX, int posBombeY, sf::Sprite& joueur, sf::Texture& textureDead, sf::Sprite& joueur2, sf::Texture& textureDead2, sf::RenderWindow& window)
{
	int caseBombX = posBombeX / SIZETILES;
	int caseBombY = posBombeY / SIZETILES;
	int caseposX, caseposY;
	int caseposX2, caseposY2;
	sf::Vector2f pos = joueur.getPosition();
	sf::Vector2f pos2 = joueur2.getPosition();
	caseposX = pos.x / SIZETILES;
	caseposY = pos.y / SIZETILES;
	caseposX2 = pos2.x / SIZETILES;
	caseposY2 = pos2.y / SIZETILES;
	if ( caseposX>= caseBombX - 1 && caseposX  <= caseBombX + 1 && caseposY >= caseBombY - 1 && caseposY <= caseBombY + 1)
	{
		joueur.setTexture(textureDead2);
		printf("Dead\n");
		menu(window, 1);


	}
	if (caseposX2 / SIZETILES >= caseBombX - 1 && caseposX2 / SIZETILES <= caseBombX + 1 && caseposY2 / SIZETILES >= caseBombY - 1 && caseposY2 / SIZETILES <= caseBombY + 1)
	{

		joueur2.setTexture(textureDead);
		printf("Dead\n");
		menu(window, 2);


	}
}
