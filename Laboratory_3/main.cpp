#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 900, 900 }), "TILES");

    const int n = 10;
    const int Size = 90;
    const int Side = 10;

    sf::RectangleShape cells[Side][Side];


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        for (int i = 0; i < Side; ++i)
        {
            for (int j = 0; j < Side; ++j)
            {
                cells[i][j].setOutlineColor(sf::Color::Black);
                cells[i][j].setOutlineThickness(1);
                cells[i][j].setSize(sf::Vector2f(Size - 1, Size - 1));
                cells[i][j].setPosition(i * Size, j * Size);

                if ((i + j) % 2 != 0) {
                    cells[i][j].setFillColor(sf::Color::Green);
                }
                else {
                    cells[i][j].setFillColor(sf::Color::White);
                }


                window.draw(cells[i][j]);
            }
        }
        window.display();
    }

    return 0;
}
