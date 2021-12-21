#include <SFML/Graphics.hpp>
#include "menu.h"




void menu(sf::RenderWindow& window,int win)
{
    sf::Texture texture;
    if (!texture.loadFromFile("background.png"))
    {
        printf("PB de chargement de l'image !\n");
    }
    sf::Texture texture3;
    if (!texture3.loadFromFile("VICTORY_1.png"))
    {
        printf("PB de chargement de l'image !\n");
    }
    sf::Texture texture2;
    if (!texture2.loadFromFile("VICTORY_2.png"))
    {
        printf("PB de chargement de l'image !\n");
    }

    sf::Sprite background;
    
    if (win == 0)
    {

        background.setTexture(texture);



        background.setPosition(1, 1);

        int leave = 0;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();            
                if ((event.mouseButton.x >= 200 && event.mouseButton.x <= 500 && event.mouseButton.y >= 450 && event.mouseButton.y <= 600 && event.mouseButton.button == sf::Mouse::Left))
                {
                    leave = 1;
                    break;
                }

                if (leave == 1)
                    break;


            }
            if (leave == 1)
                break;

            window.clear();
            window.draw(background);
            window.display();
        }
    }
    if (win == 1)
    {

        background.setTexture(texture2);
        background.setPosition(1, 1);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
             
            }
            

            window.clear();
            window.draw(background);
            window.display();
        }
    }
    if (win == 2)
    {

        background.setTexture(texture3);
        background.setPosition(1, 1);

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();        

            }


            window.clear();
            window.draw(background);
            window.display();
        }
    }

}

