#include <SFML/Graphics.hpp>
#include "game.h"
#include <SFML/Audio.hpp>
#include "menu.h"
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
// Vérifier tous les TODO



int main()
{
    sf::RenderWindow window(sf::VideoMode(650, 650), "Big Cool Bomb Party");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    sf::SoundBuffer buffer;
    buffer.loadFromFile("retro.wav");
    

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setLoop(true);
    sound.setVolume(40);
    sound.play();


    menu(window,0);
    game(window);

}
