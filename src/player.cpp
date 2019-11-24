#include "Player.h"

Player::Player(float x, float y)
{
    playerTexture.loadFromFile("textures/square.png");
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(x,y);
}

Sprite Player::returnSprite()
{
    return playerSprite;
}

void Player::moveLeft(float x,Sprite playerSprite)
{
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        playerSprite.move(x,0);
    }
}
void Player::moveRight(float x,Sprite playerSprite)
{
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        playerSprite.move(x,0);
    }
}
void Player::jump(float y,Sprite playerSprite)
{
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        playerSprite.move(0,y);
    }
}
void Player::movePlayer(float x,float y,Sprite playerSprite)
{
    moveLeft(x,playerSprite);
    moveRight(x,playerSprite);
    jump(y,playerSprite);
}
