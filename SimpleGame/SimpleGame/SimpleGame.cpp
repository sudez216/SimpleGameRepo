// SimpleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"

int main()
{
    Game Simple;
      
    while (Simple.IsCreate())
    {
        while (Window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                Window.close();
                break;
            case sf::Event::KeyPressed:
                if (Event.key.code == sf::Keyboard::Escape)
                {
                    Window.close();
                }
                break;
            }
        }
        
        Window.clear(sf::Color(200, 100, 100, 100));

        Window.display();
    }

    while (Window.pollEvent(Event))
    {
        switch (Event.type)
        {
        case sf::Event::Closed:
            Window.close();
            break;
        case sf::Event::KeyPressed:
            if (Event.key.code == sf::Keyboard::Escape)
            {
                Window.close();
            }
            break;
        }
    }

    









    










}
