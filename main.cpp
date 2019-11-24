#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Player.cpp"
#include "Platform.h"

int main()
{

    Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
    sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y), "platformer");
    Player player(0,800,resolution);
    Platform plat(100,50);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(Keyboard::isKeyPressed(Keyboard::Escape))
            {
                window.close();
            }
        }

        player.updatePlayer(plat);

        window.clear();
        window.draw(player.getShape());
        window.draw(plat.getShape());
        window.display();
    }

    return 0;
}
