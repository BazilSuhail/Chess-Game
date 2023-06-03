#include<iostream>
#include <fstream>
#include"bscs22072_chess.h"

#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
struct pos {
    int r, c;
};
pos get_xy(RenderWindow& W)
{
    sf::Event ev;
    while (1)
    {
        while (W.pollEvent(ev))
        {
            if (ev.type == ev.Closed)
                W.close();
            if (ev.type == ev.MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            {
                auto po = sf::Mouse::getPosition(W);
                return { po.y,po.x };
            }
        }
    }
}
int main() {
    RenderWindow window(sf::VideoMode(1600, 850), "CHESS");
    Texture S1;
    if (!S1.loadFromFile("background.png")) {
        cout << "Failed to load texture!";
    }
    Sprite s(S1);
    s.setPosition(0, 0);
    window.draw(s);
    window.display();
    pos p = get_xy(window);
    int br = 101, bc = 101;
    p.r = p.r / br;
    p.c = p.c / bc;
    if (p.r == 4 && p.c == 5) {
        chess game;
        game.play(window);
    }
    else {
        chess game;
        game.play_load(window);
    }
    //Texture bck;

    //if (!bck.loadFromFile("chessback.png")) {
    //    cout << "Failed to load texture!" << std::endl;
    //    //return;
    //}

    //while (window.isOpen())
    //{
    //    Sprite b3(bck);
    //    b3.setPosition(0, 0);
    //    // Main game loop
    //    // Handle events
    //    sf::Event event;
    //    while (window.pollEvent(event))
    //    {
    //        switch (event.type)
    //        {
    //            // Window closed
    //        case sf::Event::Closed:
    //            window.close();
    //            break;

    //            // Key pressed
    //        case sf::Event::KeyPressed:
    //            if (event.key.code == sf::Keyboard::U)
    //            {
    //                chess game;
    //                game.play(window);
    //            }
    //            else if (event.key.code == sf::Keyboard::U)
    //            {
    //                std::cout << "The 'n' key was pressed!\n";
    //            }
    //            else if (event.key.code == sf::Keyboard::Escape)
    //            {
    //                window.close();
    //            }
    //            break;

    //        default:
    //            break;
    //        }
    //    }

    //}


    return 0;

}