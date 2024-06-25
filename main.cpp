#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include "Personaje.h"
#include "PoweUp.h"

//director->escenas->actor
//                  ->fondo


int main()
{
    std::srand((unsigned)std::time(0));
                                         //X  //Y
    sf::RenderWindow window(sf::VideoMode(960, 320), "Shoot The Enemy");
    window.setFramerateLimit(60);



    //PJ
    Personaje Player;
    Player.setPosition(0,177);
    sf::Sprite imagen;
    sf::Texture tex;
    tex.loadFromFile("map.jpg");
    imagen.setTexture(tex);
    PowerUp Item;
    Item.Respawn();



    //GameLoop
    while (window.isOpen())
    {
        //Pool Event
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //INPUT


        //UPDATE
        Player.update();

        /*if(Player.isColision(Item)){
            Item.Respawn();
        }*/

        //DRAW -- show
        window.clear();
        window.draw(imagen);
        window.draw(Player);
        window.draw(Item);

        //Presentacion o preparacion

        //Display - flip
        window.display();
    }

    return 0;
}
