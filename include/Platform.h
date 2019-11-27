#ifndef PLATFORM_H
#define PLATFORM_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Platform
{
    private:
        RectangleShape platformRect;
    public:
        Platform(float x,float y,float X,float Y);
        RectangleShape getShape();

};

#endif // PLATFORM_H
