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
    int gravity=5;

    Vector2f resolution;
    Time totalPress;

    public:
        bool isJumping=false;

        Player(float x,float y,float X,float Y,Vector2f resolutionIn);
        void moveLeft();
        void moveRight();
        void jump();
        void movePlayer();
        RectangleShape getShape();
        void updatePlayer(Platform plat);
        bool hold = false;
        bool left = false;
        bool right = false;


};

#endif // PLAYER_H
