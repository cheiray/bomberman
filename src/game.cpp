#include <SFML/Graphics.hpp>
#include "maploader.h"
#include "playermovements.h"
#include "bomb.h"
#include "collisionCheck.h"
#include "game.h"


int game(sf::RenderWindow& window)
{

    sf::RenderTexture target;
    if (!target.create(window.getSize().x, window.getSize().y))
        return -1;

    //Texture player1
    sf::Texture imageBack1;
    sf::Texture imageBack2;
    sf::Texture imageBack3;
    sf::Texture imageForward1;
    sf::Texture imageForward2;
    sf::Texture imageForward3;
    sf::Texture imageLeft1;
    sf::Texture imageLeft2;
    sf::Texture imageLeft3;
    sf::Texture imageLeft4;
    sf::Texture imageRight1;
    sf::Texture imageRight2;
    sf::Texture imageRight3;
    sf::Texture imageRight4;
    sf::Texture bomb1;
    sf::Texture bomb2;
    // Texture player2
    sf::Texture imageBack1b;
    sf::Texture imageBack2b;
    sf::Texture imageBack3b;
    sf::Texture imageForward1b;
    sf::Texture imageForward2b;
    sf::Texture imageForward3b;
    sf::Texture imageLeft1b;
    sf::Texture imageLeft2b;
    sf::Texture imageLeft3b;
    sf::Texture imageLeft4b;
    sf::Texture imageRight1b;
    sf::Texture imageRight2b;
    sf::Texture imageRight3b;
    sf::Texture imageRight4b;

    sf::Texture mapTexture;

    //if (!mapTexture.loadFromFile("Background.png")) 
       // return -1;

    if (!imageBack1.loadFromFile("J1Back1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageBack2.loadFromFile("J1Back2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageBack3.loadFromFile("J1Back3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward1.loadFromFile("J1Forward1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward2.loadFromFile("J1Forward2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward3.loadFromFile("J1Forward3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft1.loadFromFile("J1Left1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft2.loadFromFile("J1Left2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft3.loadFromFile("J1Left3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft4.loadFromFile("J1Left4.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight1.loadFromFile("J1Right1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight2.loadFromFile("J1Right2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight3.loadFromFile("J1Right3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight4.loadFromFile("J1Right4.png"))
        printf("PB de chargement de l'image !\n");
    //Player22
    if (!imageBack1b.loadFromFile("J2Back1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageBack2b.loadFromFile("J2Back2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageBack3b.loadFromFile("J2Back3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward1b.loadFromFile("J2Forward1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward2b.loadFromFile("J2Forward2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageForward3b.loadFromFile("J2Forward3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft1b.loadFromFile("J2Left1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft2b.loadFromFile("J2Left2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft3b.loadFromFile("J2Left3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageLeft4b.loadFromFile("J2Left4.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight1b.loadFromFile("J2Right1.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight2b.loadFromFile("J2Right2.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight3b.loadFromFile("J2Right3.png"))
        printf("PB de chargement de l'image !\n");
    if (!imageRight4b.loadFromFile("J2Right4.png"))
        printf("PB de chargement de l'image !\n");
    if (!bomb1.loadFromFile("bomb1.png"))
        printf("pas marché");
    if (!bomb2.loadFromFile("bomb2.png"))
        printf("pas marché");
    sf::Texture textureDead;
    if (!textureDead.loadFromFile("mort_joueur_1.png"))
        printf("PB de chargement de l'image !\n");
    sf::Texture textureDead2;
    if (!textureDead2.loadFromFile("mort_joueur_2.png"))
        printf("PB de chargement de l'image !\n");

    sf::Vector2f player1(250, 50);
    sf::Vector2f player2(550, 550);
    sf::Vector2f player1Sav;
    sf::Vector2f player2Sav;
    int mapLevel[169] =
    {   2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
        2, 1, 0, 3, 3, 0, 1, 0, 1, 1, 0, 0, 2,
        2, 0, 2, 3, 2, 1, 2, 1, 2, 1, 2, 0, 2,
        2, 3, 3, 0, 0, 1, 0, 1, 0, 0, 1, 1, 2,
        2, 3, 2, 1, 2, 1, 2, 1, 2, 1, 2, 0, 2,
        2, 0, 1, 1, 0, 3, 3, 3, 0, 1, 1, 0, 2,
        2, 0, 2, 1, 2, 3, 4, 3, 2, 1, 2, 0, 2,
        2, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 2,
        2, 0, 2, 1, 2, 1, 2, 1, 2, 1, 2, 3, 2,
        2, 1, 1, 0, 1, 1, 0, 1, 1, 0, 3, 3, 2,
        2, 0, 2, 1, 2, 0, 2, 0, 2, 3, 2, 0, 2,
        2, 0, 0, 1, 1, 0, 1, 0, 3, 3, 0, 1, 2,
        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    };
    std::vector<TypeTile> destroyableTiles[NBRTILE3];
    sf::Vector3f destroyableTile[169];
    sf::Vector2f tilesBlocking[169];
    sf::Sprite map(mapTexture);
    sf::Sprite paddle1;
    sf::Sprite paddle2;
    sf::Sprite bombe1;
    sf::Sprite bombe2;
    paddle1.setTexture(imageBack1);
    paddle2.setTexture(imageBack1b);
    bombe1.setTexture(bomb1);
    bombe2.setTexture(bomb2);
    /*bombe1.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    bombe2.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    paddle1.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    paddle2.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);*/
    bombe1.setPosition(-100, -100);
    bombe2.setPosition(-100, -100);
    // Charger la map
       // mapLoader(target);
       /* target.clear(sf::Color::White);
        target.draw(, sf::BlendAlpha);
        target.display();*/
        //target.display();
      //  sf::Sprite map2(target.getTexture()); // stocker la texture créé dans le Sprite map2
    // Fin Charger la map

        // Initialisation des variables
        //Variables pour les animations des déplacements
        //player1
    int firstForward = 0;
    int firstBack = 0;
    int firstLeft = 0;
    int firstRight = 0;
    int bombJ1 = 0;
    //player2
    int firstForward2 = 0;
    int firstBack2 = 0;
    int firstLeft2 = 0;
    int firstRight2 = 0;
    int bombJ2 = 0;

    //time
    sf::Clock clock;
    sf::Clock clockUp;
    sf::Clock clockDown;
    sf::Clock clockRight;
    sf::Clock clockLeft;
    sf::Clock clockBomb1;
    sf::Clock clockBomb2;
    sf::Time time;
    sf::Time timeUp;
    sf::Time timeDown;
    sf::Time timeRight;
    sf::Time timeLeft;
    sf::Time timeBomb1;
    sf::Time timeBomb2;

    //player1
    float dt = 0;
    float dtUp = 0;
    float dtDown = 0;
    float dtRight = 0;
    float dtLeft = 0;
    float dtBomb1 = 0;

    //player2
    //float dt2 = 0;
    float dtUp2 = 0;
    float dtDown2 = 0;
    float dtRight2 = 0;
    float dtLeft2 = 0;
    float dtBomb2 = 0;

    float compteur = 0;
    int speed = 200;

    int caseX = 0;
    int caseY = 0;
    //paddle1.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    //paddle2.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    /*bombe1.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);
    bombe2.setOrigin(TAILLE_CASE / 2, TAILLE_CASE / 2);*/
    int remoteExplode1;
    int remoteExplode2;
    char saveLastPos, saveLastPos2; // To prevent players from gliding onto the walls
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::Space && bombJ2 == 0) // Espace== place bombe J2
            {


                place_bomb(player2, bombe1);
                bombJ2 = 1;
                remoteExplode1 = 0;

            }
            if (event.key.code == sf::Keyboard::Enter && bombJ1 == 0) //Enter == place bombe J1
            {

                place_bomb(player1, bombe2);
                bombJ1 = 1;
                remoteExplode2 = 0;

            }
            if (event.key.code == sf::Keyboard::LAlt && bombJ2 == 1) //Enter == place bombe J1
            {

                
                remoteExplode1 = 1;
                //bombJ2 = 0;
                

            }
            if (event.key.code == sf::Keyboard::Numpad0 && bombJ1 == 1) //Enter == place bombe J1
            {


                remoteExplode2 = 1;
               // bombJ1 = 0;
            }
            
        }

        if (bombJ2 > 0)
        {
            diparition_bomb(bombe1, dtBomb1, bombJ2, clockBomb1, destroyableTile, mapLevel, paddle1, textureDead2, paddle2, textureDead,window,remoteExplode1);

        }
        if (bombJ1 > 0)
        {
            diparition_bomb(bombe2, dtBomb2, bombJ1, clockBomb2, destroyableTile, mapLevel, paddle1, textureDead2, paddle2, textureDead,window,remoteExplode2);

        }

        // Debut mouvement joueurs


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) // Fleche gauche appuyee
        {
            if (checkPlayerPos(player1, tilesBlocking, 'R',saveLastPos, speed, dt))
            {
                player1Sav = player1;
                move_left(player1, paddle1, imageLeft1, imageLeft2, imageLeft3, clockLeft, speed, dt, dtLeft, firstLeft);
                saveLastPos = 'R';
            }
            else
            {
                player1 = player1Sav;
            }
           
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) // Fleche droite appuyee
        {
            if (checkPlayerPos(player1, tilesBlocking, 'L',saveLastPos, speed, dt))
            {
                player1Sav = player1;
                move_right(player1, paddle1, imageRight1, imageRight2, imageRight3, clockRight, speed, dt, dtRight, firstRight);
                saveLastPos = 'L';
            }
            else
            {
                player1 = player1Sav;
            }
           

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) // Fleche du haut appuyee
        {
            if (checkPlayerPos(player1, tilesBlocking, 'D',saveLastPos, speed, dt))
            {
                player1Sav = player1;
                move_up(player1, paddle1, imageForward1, imageForward2, imageForward3, clockUp, speed, dt, dtUp, firstForward);
                saveLastPos = 'D';
            }
            else
            {
                player1 = player1Sav;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))) // Fleche du bas appuyee
        {
            if (checkPlayerPos(player1, tilesBlocking, 'U',saveLastPos, speed, dt))
            {
                player1Sav = player1;
                move_down(player1, paddle1, imageBack1, imageBack2, imageBack3, clockUp, speed, dt, dtUp, firstForward);
                saveLastPos = 'U';
            }
            else
            {
                player1 = player1Sav;
            }
        }
        //player 2

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))) // Fleche gauche appuyee
        {
            if (checkPlayerPos(player2, tilesBlocking, 'L',saveLastPos2,speed,dt))
            {
                player2Sav = player2;
                move_left(player2, paddle2, imageLeft1b, imageLeft2b, imageLeft3b, clockLeft, speed, dt, dtLeft2, firstLeft2);
                saveLastPos2 = 'L';
            }
            else
            {
                player2 = player2Sav;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))) // Fleche droite appuyee
        {
            if (checkPlayerPos(player2, tilesBlocking, 'R',saveLastPos2, speed, dt))
            {
                player2Sav = player2;
                move_right(player2, paddle2, imageRight1b, imageRight2b, imageRight3b, clockRight, speed, dt, dtRight2, firstRight2);
                saveLastPos2 = 'R';
            }
            else
            {
                player2 = player2Sav;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))) // Fleche du haut appuyee
        {
            if (checkPlayerPos(player2, tilesBlocking, 'U',saveLastPos2, speed, dt))
            {
                player2Sav = player2;
                move_up(player2, paddle2, imageForward1b, imageForward2b, imageForward3b, clockUp, speed, dt, dtUp2, firstForward2);
                saveLastPos2 = 'U';
            }
            else
            {
                player2 = player2Sav;
            }

        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))) // Fleche du bas appuyee
        {
            if (checkPlayerPos(player2, tilesBlocking, 'D',saveLastPos2, speed, dt))
            {
                player2Sav = player2;
                move_down(player2, paddle2, imageBack1b, imageBack2b, imageBack3b, clockDown, speed, dt, dtDown2, firstBack2);
                saveLastPos2 = 'D';
            }
            else
            {
                player2 = player2Sav; // this is the best way to handle a collision it'll prevent some weird glitch
            }

        }


        // Fin deplacement joueurs
        time = clock.restart();
        dt = time.asSeconds();
        // Update players movement
        paddle1.setPosition(player1.x, player1.y);
        paddle2.setPosition(player2.x, player2.y);



        //map
        mapLoader(target, mapLevel, destroyableTile, tilesBlocking);
        sf::Sprite map2(target.getTexture()); // stocker la texture créé dans le Sprite map2
        //fin map

        window.clear();
        window.draw(map2);
        window.draw(bombe1);
        window.draw(bombe2);
        window.draw(paddle1);
        window.draw(paddle2);
        window.display();
    }
}