#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include "Platform.h"
using namespace sf;
class Player
{
    private:
    RectangleShape playerRect;

    float lastX;
    float lastY;
    int gravity=2;

    Vector2f resolution;

    public:
        Player(float x,float y,Vector2f resolutionIn);
        void moveLeft();
        void moveRight();
        void jump();
        void movePlayer();
        RectangleShape getShape();
        void updatePlayer(Platform plat);


};

#endif // PLAYER_H
