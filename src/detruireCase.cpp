#include <SFML/Graphics.hpp>
#include "detruireCase.h"
#include "maploader.h"

/*void detruireCase(int posBombeX, int posBombeY, sf::Vector3f destroyableTile[], int maplevel[])
{
	int distancePosY;
	int distancePosY2;
	int distancePosX;
	int distancePosX2;
	int level;
	for (int i = 0; i < 121; i++)
	{
		distancePosY =   posBombeY- destroyableTile[i].y;
		distancePosY2 = destroyableTile[i].y - posBombeY;
		distancePosX = posBombeX - destroyableTile[i].x;
		distancePosX2 = destroyableTile[i].x - posBombeX;
		if (destroyableTile[i].x - posBombeX >= -25 && destroyableTile[i].x - posBombeX <= SIZETILES-25 && distancePosY<50&& (distancePosY >= 0 || distancePosY2 >= 50) && distancePosY2 <= 100)//&& destroyableTile[i].y - posBombeY >= 0 && destroyableTile[i].y - posBombeY >= SIZETILES)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile
			printf("distance = %i\n\n", distancePosY);
			printf("distance2 = %i\n\n", distancePosY2);
			
		}

		if (destroyableTile[i].y - posBombeY >= -25 && destroyableTile[i].y - posBombeY <= SIZETILES - 25 && distancePosX < 50 && distancePosX >= 0 || (distancePosX < 0 && distancePosX >= -50))//&& (distancePosX >= 0 || distancePosX2 >= 50) && distancePosX2 <= 100)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile
		}

		/*if (destroyableTile[i].y - posBombeY >= -25 && destroyableTile[i].y - posBombeY <= SIZETILES-25)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile
		}
	}
	
}*/
void detruireCase(int posBombeX, int posBombeY, sf::Vector3f destroyableTile[], int maplevel[])
{
	int caseBombX = posBombeX / SIZETILES;
	int caseBombY = posBombeY / SIZETILES;
	int level;
	for (int i = 0; i < 121; i++)
	{
		
		if (destroyableTile[i].x/SIZETILES >= caseBombX-1 && destroyableTile[i].x/SIZETILES<=caseBombX+1 && destroyableTile[i].y / SIZETILES >= caseBombY - 1 && destroyableTile[i].y / SIZETILES <= caseBombY + 1)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile

		}
		/*if (destroyableTile[i].y / SIZETILES >= caseBombY - 1 && destroyableTile[i].y / SIZETILES <= caseBombY + 1)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile

		}

		/*if (destroyableTile[i].y - posBombeY >= -25 && destroyableTile[i].y - posBombeY <= SIZETILES-25)
		{
			level = destroyableTile[i].z;
			maplevel[level] = 0; //3 is destroyable Tile
		}*/
	}

}