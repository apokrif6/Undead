#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH = 640;
#define SCREEN_HEIGHT = 480;

int main()
{
    int modeWidth = 640;
    int modeHeight = 480;

    sf::RenderWindow window(sf::VideoMode(modeWidth, modeHeight), "SFML Application");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition((float)modeWidth / 2, (float)modeHeight /2);
    shape.setFillColor(sf::Color::Magenta);

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}
