#include "Platform.h"
#include <SFML/Graphics.hpp>
Platform::Platform(float x,float y,float X,float Y)
{
    platformRect.setFillColor(Color(0,255,255));
    platformRect.setPosition(Vector2f(x,y));
    platformRect.setSize(Vector2f(X,Y));
}

RectangleShape Platform::getShape()
{
    return platformRect;
}
