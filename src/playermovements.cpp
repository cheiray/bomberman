#include <SFML/Graphics.hpp>
// #include "playermovements.h" TODO Verifier si cette ligne est bien inutile
//TODO Penser à enlever dtUp = elapsed.asSeconds(); de chaque boucle et le mettre a la fin du void
void move_left(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtLeft, int& firstmov)
{
    sf::Time elapsed = clockUp.getElapsedTime();
    player.x -= speed * dt;
    if (firstmov == 0 && elapsed.asSeconds() - dtLeft >= 0.15)
    {
        paddle.setTexture(image);
        firstmov = 1;
        dtLeft= elapsed.asSeconds();
    }
    if (firstmov == 1 && elapsed.asSeconds() - dtLeft >= 0.15)
    {
        paddle.setTexture(image2);
        firstmov = 2;
        dtLeft = elapsed.asSeconds();
    }
    if (firstmov == 2 && elapsed.asSeconds() - dtLeft >= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 3;
        dtLeft = elapsed.asSeconds();
    }
    if (firstmov == 3 && elapsed.asSeconds() - dtLeft>= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 0;
        dtLeft = elapsed.asSeconds();
    }
}

void move_right(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtRight, int& firstmov)
{
    sf::Time elapsed = clockUp.getElapsedTime();
    player.x += speed * dt;
    if (firstmov == 0 && elapsed.asSeconds() - dtRight >= 0.15)
    {
        paddle.setTexture(image);
        firstmov = 1;
        dtRight = elapsed.asSeconds();
    }
    if (firstmov == 1 && elapsed.asSeconds() - dtRight >= 0.15)
    {
        paddle.setTexture(image2);
        firstmov = 2;
        dtRight = elapsed.asSeconds();
    }
    if (firstmov == 2 && elapsed.asSeconds() - dtRight >= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 3;
        dtRight = elapsed.asSeconds();
    }
    if (firstmov == 3 && elapsed.asSeconds() - dtRight>= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 0;
        dtRight = elapsed.asSeconds();
    }
}

void move_up(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtUp, int& firstmov)
{
    sf::Time elapsed = clockUp.getElapsedTime();
    player.y -= speed * dt;
    // Code pour animer la démarche des personnages
    if (firstmov == 0 && elapsed.asSeconds() - dtUp >= 0.15)
    {
        paddle.setTexture(image);
        firstmov = 1;
        dtUp = elapsed.asSeconds();
    }
    if (firstmov == 1 && elapsed.asSeconds() - dtUp >= 0.15)
    {
        paddle.setTexture(image2);
        firstmov = 2;
        dtUp = elapsed.asSeconds();
    }
    if (firstmov == 2 && elapsed.asSeconds() - dtUp >= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 0;
        dtUp = elapsed.asSeconds();
    }
}

void move_down(sf::Vector2f& player, sf::Sprite& paddle, sf::Texture& image, sf::Texture& image2, sf::Texture& image3, sf::Clock& clockUp, int speed, float dt, float& dtDown, int& firstmov)
{
    sf::Time elapsed = clockUp.getElapsedTime();
    player.y += speed * dt;
    // Code pour animer la démarche des personnages
    if (firstmov == 0 && elapsed.asSeconds() - dtDown >= 0.15)
    {
        paddle.setTexture(image);
        firstmov = 1;
        dtDown = elapsed.asSeconds();
    }
    if (firstmov == 1 && elapsed.asSeconds() - dtDown >= 0.15)
    {
        paddle.setTexture(image2);
        firstmov = 2;
        dtDown = elapsed.asSeconds();
    }
    if (firstmov == 2 && elapsed.asSeconds() - dtDown >= 0.15)
    {
        paddle.setTexture(image3);
        firstmov = 0;
        dtDown = elapsed.asSeconds();
    }
}
