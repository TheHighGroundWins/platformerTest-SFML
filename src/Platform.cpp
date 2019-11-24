#include "Platform.h"
#include <SFML/Graphics.hpp>
Platform::Platform(float x,float y)
{
    platformRect.setFillColor(Color(0,255,255));
    platformRect.setPosition(Vector2f(100,200));
    platformRect.setSize(Vector2f(x,y));
}

RectangleShape Platform::getShape()
{
    return platformRect;
}
